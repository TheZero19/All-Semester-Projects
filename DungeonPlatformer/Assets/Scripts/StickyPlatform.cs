using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class StickyPlatform : MonoBehaviour
{
    //-------------------------------------------------------------------------------------------------------------
    //making player attached to the platform when on the platform.
    //-------------------------------------------------------------------------------------------------------------


    //if the player touches the platform, set player as the parent of platform.
    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.gameObject.name == "Player") { 
            collision.gameObject.transform.SetParent(transform);
        }
    }

    //if the player leaves the platform, don't make the player as the parent of platform anymore.
    private void OnCollisionExit2D(Collision2D collision)
    {
        if (collision.gameObject.name == "Player")
        {
            collision.gameObject.transform.SetParent(null);
        }
    }
}