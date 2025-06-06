#include "robot_simulator.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

robot_status_t robot_create(robot_direction_t direction, int x, int y) {
	return (robot_status_t){
	    .direction = direction >= DIRECTION_MAX ? 0 : direction,
	    .position = {.x = x, .y = y}};
}

static void robot_turn_right(robot_status_t *robot) {
	switch (robot->direction) {
		case DIRECTION_NORTH:
			robot->direction = DIRECTION_EAST;
			break;
		case DIRECTION_EAST:
			robot->direction = DIRECTION_SOUTH;
			break;
		case DIRECTION_SOUTH:
			robot->direction = DIRECTION_WEST;
			break;
		case DIRECTION_WEST:
			robot->direction = DIRECTION_NORTH;
			break;
		default:
			printf("Robot direction in invalid state\n");
			exit(EXIT_FAILURE);
	}
}

static void robot_turn_left(robot_status_t *robot) {
	switch (robot->direction) {
		case DIRECTION_NORTH:
			robot->direction = DIRECTION_WEST;
			break;
		case DIRECTION_EAST:
			robot->direction = DIRECTION_NORTH;
			break;
		case DIRECTION_SOUTH:
			robot->direction = DIRECTION_EAST;
			break;
		case DIRECTION_WEST:
			robot->direction = DIRECTION_SOUTH;
			break;
		default:
			printf("Robot direction in invalid state\n");
			exit(EXIT_FAILURE);
	}
}

static void robot_advance(robot_status_t *robot) {
	switch (robot->direction) {
		case DIRECTION_NORTH:
			robot->position.y++;
			break;
		case DIRECTION_EAST:
			robot->position.x++;
			break;
		case DIRECTION_SOUTH:
			robot->position.y--;
			break;
		case DIRECTION_WEST:
			robot->position.x--;
			break;
		default:
			printf("Robot direction in invalid state\n");
			exit(EXIT_FAILURE);
	}
}

void robot_move(robot_status_t *robot, const char *commands) {
	for (size_t i = 0; i < strlen(commands); i++) {
		char command = commands[i];
		switch (command) {
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