/*
 * error.h
 *
 *  Created on: Nov 5, 2024
 *      Author: ADMINS
 */

#ifndef INC_ERROR_H_
#define INC_ERROR_H_

#define ERROR_SCH_TOO_MANY_TASKS						1
#define ERROR_SCH_WAITING_FOR_SLAVE_TO_ACK				2
#define ERROR_SCH_WAITING_FOR_START_COMMAND_FROM_MASTER 3
#define ERROR_SCH_ONE_OR_MORE_SLAVES_DID_NOT_START		4
#define ERROR_SCH_LOST_SLAVE							5
#define ERROR_SCH_CAN_BUS_ERROR							6
#define ERROR_I2C_WRITE_BYTE_AT24C64					7
#define ERROR_SCH_CANNOT_DELETE_TASK					8

extern unsigned char Error_code_G;

extern int Error_tick_count_G;

extern unsigned char Last_error_code_G;

#endif /* INC_ERROR_H_ */
