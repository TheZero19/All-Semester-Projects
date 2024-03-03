using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Gun : MonoBehaviour
{
    [Header("References")]
    [SerializeField] private GunData gunData;
    [SerializeField] private Transform muzzle;

    float timeSinceLastShot;

    private void Start()
    {
        PlayerShoot.shootInput += Shoot;//here, the action of shootInput from "PlayerShoot.cs" is being incremented by calling the Shoot() method in "Gun.cs"
        PlayerShoot.reloadInput += StartReload; //subscribing the "reload" event to the call, similar to "shooting".
    }

    public void StartReload()
    {
        if (!gunData.reloading)
        {
            //reloading...
            StartCoroutine(Reload());
        }
    }

    private IEnumerator Reload()
    {
        //a subroutine made from IEnumerator to make a player wait a few moment and "refill" the mag.
        gunData.reloading = true;
        
        yield return new WaitForSeconds(gunData.reloadTime);

        gunData.currentAmmo = gunData.magSize;

        gunData.reloading = false;
    }

    private bool CanShoot()
    {
        //checking if we are able to shoot: i.e. if we are not reloading and the time between bullets fired is viable:
        if(!gunData.reloading && timeSinceLastShot > 1f / (gunData.fireRate / 60f))
        {
            return true;
        }
        return false;
  
    }

    public void Shoot()
    {
        if(gunData.currentAmmo > 0)
        {
            if (CanShoot())
            {
                if (Physics.Raycast(muzzle.position, transform.forward, out RaycastHit hitInfo, gunData.maxDistance))
                {

                    Debug.Log(hitInfo.transform.name);
                    ////getting the component out of the target we've hit with our bullet(s)
                    //IDamageable damageable = hitInfo.transform.GetComponent<IDamageable>();
                    ////and damaging the object with the amount of damage as specified in the gunData.
                    //damageable?.TakeDamage(gunData.damage);
                }

                gunData.currentAmmo--;
                timeSinceLastShot = 0;
                OnGunShot();
            }
        }
    }

    private void Update()
    {
        timeSinceLastShot += Time.deltaTime;

        Debug.DrawRay(muzzle.position, muzzle.forward);
    }

    //a function to add post gunfire elements(not currently utilized, served as a vessel..)
    private void OnGunShot()
    {
        throw new NotImplementedException();
    }
}
