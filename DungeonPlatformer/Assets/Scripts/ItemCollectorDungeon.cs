using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI; //to use the type "Text".

public class ItemCollectorDungeon : MonoBehaviour
{
    private int items = 0;
    [SerializeField] private Text strawberriesText;


    //overwriting the OnTriggerEnter2D.
    //If on trigger was unchecked, we had to use boxCollider2D instead.
    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.gameObject.CompareTag("Items"))
        {
            Destroy(collision.gameObject);
            items++;
            strawberriesText.text = "Items Collected: " + items;
        }
    }
}
