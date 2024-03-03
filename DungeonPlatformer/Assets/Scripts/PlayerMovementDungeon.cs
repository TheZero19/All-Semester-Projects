using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMovementDungeon : MonoBehaviour
{
    //private makes our variables and methods only accessible in the given script.
    private Rigidbody2D rb;
    private Animator anim;

    private BoxCollider2D coll;

    private float dirX;

    private SpriteRenderer spriteRenderer;

    [SerializeField] private float speed = 10f;

    [SerializeField] private LayerMask jumpableGround;

    // Start is called before the first frame update
    private void Start()
    {
        rb = GetComponent<Rigidbody2D>();
        anim = GetComponent<Animator>();
        spriteRenderer = GetComponent<SpriteRenderer>();
        coll = GetComponent<BoxCollider2D>();
    }

    // Update is called once per frame
    private void Update()
    {

        dirX = Input.GetAxisRaw("Horizontal"); //Input manager has "Horizontal" named section for movement in X-direction.
        //dirX cannot be 1 or -1 only if we are using Joystick for input while playing the game.

        rb.velocity = new Vector2(dirX * speed, rb.velocity.y); //dirX can be -ve for negative X-axis and vice versa. We have a default speed of 7 units of float type.
        //The player has to keep the previous frame's velocity in the upward direction in the next frame too.
        //Instead of 0, we use rb.velocity.y

        if (Input.GetButtonDown("Jump") && isGrounded())
        {
            GetComponent<Rigidbody2D>().velocity = new Vector2(rb.velocity.x, 14); //We are working on 2D so, a vector2 is sufficient.
        }
        //rb.velocity.x for the same reason as rb.velocity.y in previous case.

        updateAnimation();
        
    }

    private void updateAnimation()
    {
        if (dirX > 0f)
        {
            anim.SetBool("isRunning", true); //sets bool parameter in Animator window to true.
            spriteRenderer.flipX = false;
        }
        else if (dirX < 0f)
        {
            anim.SetBool("isRunning", true); //sets bool parameter in Animator window to true.
            spriteRenderer.flipX = true;
        }
        else
        {
            anim.SetBool("isRunning", false); //sets bool parameter in Animator window to false.
        }
    }

    //eliminating multiple jumps
    private bool isGrounded()
    {
        return Physics2D.BoxCast(coll.bounds.center, coll.bounds.size, 0f, Vector2.down, .1f, jumpableGround);
    }

    //isGrounded creates a new box collider around our player from first two parameters as the size and origin.
    //and needs offset from the original collider. We are checking if the layer of the ground is overlapping with new box collider  to check if the player is grounded.
    //for our case, the player is grounded when the grid we made are of Layer "Ground".
}
