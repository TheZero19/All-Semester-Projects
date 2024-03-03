using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SawRotationDungeon : MonoBehaviour
{
    [SerializeField] private float rotationRate = 2f;        

    // Update is called once per frame
    void Update()
    {
        //since the z-direction according to unity is towards us, the rotation of saw is done in Z-direction.

        transform.Rotate(0, 0, 360 * rotationRate * Time.deltaTime); //Time.deltaTime here also makes the rotation independent of FPS.
    }
}
