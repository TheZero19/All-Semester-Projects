using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class WaypointFollowerDungeon : MonoBehaviour
{
    [SerializeField] private GameObject[] waypoints;
    private int currentWaypointIndex = 0;

    [SerializeField] private float speed = 2f;

    private void Update()
    {
        //if the distance between a waypoint and the platform is less than 0.1, we change the index of the waypoint.
        //and if the waypoint that was followed was the last waypoint, we change the index to 0, i.e first waypoint. 
        if (Vector2.Distance(waypoints[currentWaypointIndex].transform.position, transform.position) < .1f)
        {
            currentWaypointIndex++;
            if(currentWaypointIndex >= waypoints.Length)
            {
                currentWaypointIndex = 0;
            }
        }

        //specifying the rate at which the platform moves.
        //Time.delta time makes the velocity independent of frame rate of the computer.
        transform.position = Vector2.MoveTowards(transform.position, waypoints[currentWaypointIndex].transform.position, Time.deltaTime * speed);
    }
}
