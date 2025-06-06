#include "robot_simulator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

robot_grid_status_t robot_init(void)
{
    return (robot_grid_status_t){
        .bearing = DEFAULT_BEARING,
        .grid = {
            .x_position = DEFAULT_X_COORDINATE,
            .y_position = DEFAULT_Y_COORDINATE}};
}

robot_grid_status_t robot_init_with_position(int bearing, int x, int y)
{
    return (robot_grid_status_t){
        .bearing = bearing >= HEADING_MAX ? 0 : bearing,
        .grid = {
            .x_position = x,
            .y_position = y}};
}

void robot_turn_right(robot_grid_status_t *robot)
{
    switch (robot->bearing)
    {
    case HEADING_NORTH:
        robot->bearing = HEADING_EAST;
        break;
    case HEADING_EAST:
        robot->bearing = HEADING_SOUTH;
        break;
    case HEADING_SOUTH:
        robot->bearing = HEADING_WEST;
        break;
    case HEADING_WEST:
        robot->bearing = HEADING_NORTH;
        break;
    default:
        printf("Robot Bearing in invalid state\n");
        exit(EXIT_FAILURE);
    }
}

void robot_turn_left(robot_grid_status_t *robot)
{
    switch (robot->bearing)
    {
    case HEADING_NORTH:
        robot->bearing = HEADING_WEST;
        break;
    case HEADING_EAST:
        robot->bearing = HEADING_NORTH;
        break;
    case HEADING_SOUTH:
        robot->bearing = HEADING_EAST;
        break;
    case HEADING_WEST:
        robot->bearing = HEADING_SOUTH;
        break;
    default:
        printf("Robot Bearing in invalid state\n");
        exit(EXIT_FAILURE);
    }
}

void robot_advance(robot_grid_status_t *robot)
{
    switch (robot->bearing)
    {
    case HEADING_NORTH:
        robot->grid.y_position++;
        break;
    case HEADING_EAST:
        robot->grid.x_position++;
        break;
    case HEADING_SOUTH:
        robot->grid.y_position--;
        break;
    case HEADING_WEST:
        robot->grid.x_position--;
        break;
    default:
        printf("Robot Bearing in invalid state\n");
        exit(EXIT_FAILURE);
    }
}

void robot_simulator(robot_grid_status_t *robot, const char *commands)
{
    for (size_t i = 0; i < strlen(commands); i++)
    {
        char command = commands[i];
        switch (command)
        {
        case 'R':
            robot_turn_right(robot);
            break;
        case 'L':
            robot_turn_left(robot);
            break;
        case 'A':
            robot_advance(robot);
            break;
        }
    }
}