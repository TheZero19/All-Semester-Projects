using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class PlayerLifeDungeon : MonoBehaviour
{
    private Rigidbody2D rb;
    private void Start()
    {
        rb = GetComponent<Rigidbody2D>();
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.gameObject.CompareTag("Traps"))
        {
            Die();
        }
    }

    private void Die()
    {
        //we have something to do still.. Death animation!


        //RigidbodyType2D changed to static when we encounter collision with game objects tagged as "Traps".
        //Once we hit the traps, we assume the player dies.
        rb.bodyType = RigidbodyType2D.Static;


        //We need to specify the time before the player respawns.
        //Allocating that the "RestartLevel" function should be invoked after 1 second.
        Invoke("RestartLevel", 1f);
    }

    private void RestartLevel()
    { 
        SceneManager.LoadScene(SceneManager.GetActiveScene().name);
    }

}
