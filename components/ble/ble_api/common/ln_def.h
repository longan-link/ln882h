/**
 ****************************************************************************************
 *
 * @file ln_def.h
 *
 * @brief define  API.
 *
 *Copyright (C) 2021.Shanghai Lightning Semiconductor Ltd
 *
 *
 ****************************************************************************************
 */

#ifndef _LN_DEF_H_
#define _LN_DEF_H_

/**
 ****************************************************************************************
 * @addtogroup APP
 * 
 *
 * @brief define API.
 *
 * @{
 ****************************************************************************************
 */


/*
 * INCLUDE FILES
 ****************************************************************************************
 */

#include <stdint.h>
#include <stdbool.h>


/*
 * DEFINES
 ****************************************************************************************
 */
#define BLE_USR_MSG_QUEUE_SIZE    96

#define LN_MALLOC_CHECK(cond)                                                           \
     do {                                                                            \
         if (!(cond)) {                                                              \
                LOG(LOG_LVL_ERROR, "malloc error  %s  %d \r\n",__FILE__ ,__LINE__);  \
         }                                                                           \
     } while(0) 


typedef struct
{
    uint16_t  id;
    uint16_t  len;
    void     *msg;
} ble_usr_msg_t;

enum ble_usr_msg_type
{
    BLE_MSG_WRITE_DATA,
    BLE_MSG_CONN_IND,
    BLE_MSG_SVR_DIS,
};

/// States of APP task
enum app_state
{
    /// Initialization state
    APP_INIT,
    /// Database create state
    APP_CREATE_DB,
    /// Ready State
    APP_READY,
    /// Connected state
    APP_CONNECTED,
    /// advertising
    APP_ADVERTISING,

    /// Number of defined states.
    APP_STATE_MAX
};

/*
 * FUNCTION DECLARATIONS
 ****************************************************************************************
 */
void usr_creat_queue(void);
void usr_queue_msg_send(uint16_t id, uint16_t length, void *msg);
int  usr_queue_msg_recv(void *msg, uint32_t timeout);

void usr_creat_semaphore(void);
void usr_acquire_semaphore(void);
void usr_release_semaphore(void);
void usr_delete_semaphore(void);

/**
 ****************************************************************************************
 * @brief  send ke message
 *
 * @param[in] param_ptr             Pointer to the parameter member of the message that
 *                                                         should be sent.
 ****************************************************************************************
 */

void ln_ke_msg_send(void const *param_ptr);




#endif // _APP_GAP_H_
