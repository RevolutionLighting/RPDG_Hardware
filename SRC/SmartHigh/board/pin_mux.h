/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

/*!
 * @brief UART 0 Receive Data Source Select: UART0_RX pin */
#define SOPT5_UART0RXSRC_UART_RX 0x00u
/*!
 * @brief UART 0 Transmit Data Source Select: UART0_TX pin */
#define SOPT5_UART0TXSRC_UART_TX 0x00u
/*!
 * @brief FTM0 channel 0 output PWM/OCMP mode source select: FTM0CH0 pin is the output of FTM0 channel 0 PWM/OCMP */
#define SOPT8_FTM0OCH0SRC_NO_MODULATION 0x00u
/*!
 * @brief FTM0 channel 1 output PWM/OCMP mode source select: FTM0CH1 pin is the output of FTM0 channel 1 PWM/OCMP */
#define SOPT8_FTM0OCH1SRC_NO_MODULATION 0x00u
/*!
 * @brief FTM0 channel 2 output PWM/OCMP mode source select: FTM0CH2 pin is the output of FTM0 channel 2 PWM/OCMP */
#define SOPT8_FTM0OCH2SRC_NO_MODULATION 0x00u
/*!
 * @brief FTM0 channel 3 output PWM/OCMP mode source select: FTM0CH3 pin is the output of FTM0 channel 3 PWM/OCMP */
#define SOPT8_FTM0OCH3SRC_NO_MODULATION 0x00u
/*!
 * @brief FTM0 channel 4 output PWM/OCMP mode source select: FTM0CH4 pin is the output of FTM0 channel 4 PWM/OCMP */
#define SOPT8_FTM0OCH4SRC_NO_MODULATION 0x00u
/*!
 * @brief FTM0 channel 5 output PWM/OCMP mode source select: FTM0CH5 pin is the output of FTM0 channel 5 PWM/OCMP */
#define SOPT8_FTM0OCH5SRC_NO_MODULATION 0x00u
/*!
 * @brief FTM2 channel 0 output PWM/OCMP mode source select: FTM2CH0 pin is the output of FTM2 channel 0 PWM/OCMP */
#define SOPT8_FTM2OCH0SRC_NO_MODULATION 0x00u
/*!
 * @brief FTM2 channel 1 output PWM/OCMP mode source select: FTM2CH1 pin is the output of FTM2 channel 1 PWM/OCMP */
#define SOPT8_FTM2OCH1SRC_NO_MODULATION 0x00u
/*!
 * @brief FTM4 channel 0 output PWM/OCMP mode source select: FTM4CH0 pin is the output of FTM4 channel 0 PWM/OCMP */
#define SOPT9_FTM4OCH0SRC_NO_MODULATION 0x00u
/*!
 * @brief FTM4 channel 1 output PWM/OCMP mode source select: FTM4CH1 pin is the output of FTM4 channel 1 PWM/OCMP */
#define SOPT9_FTM4OCH1SRC_NO_MODULATION 0x00u

/*! @name PORTE16 (number 3), TP2
  @{ */
#define BOARD_INITPINS_TP2_GPIO GPIOE /*!<@brief GPIO device name: GPIOE */
#define BOARD_INITPINS_TP2_PORT PORTE /*!<@brief PORT device name: PORTE */
#define BOARD_INITPINS_TP2_PIN 16U    /*!<@brief PORTE pin index: 16 */
                                      /* @} */

/*! @name PORTE17 (number 4), TP3
  @{ */
#define BOARD_INITPINS_TP3_GPIO GPIOE /*!<@brief GPIO device name: GPIOE */
#define BOARD_INITPINS_TP3_PORT PORTE /*!<@brief PORT device name: PORTE */
#define BOARD_INITPINS_TP3_PIN 17U    /*!<@brief PORTE pin index: 17 */
                                      /* @} */

/*! @name PORTE18 (number 5), SDA
  @{ */
#define BOARD_INITPINS_SDA_PORT PORTE /*!<@brief PORT device name: PORTE */
#define BOARD_INITPINS_SDA_PIN 18U    /*!<@brief PORTE pin index: 18 */
                                      /* @} */

/*! @name PORTE19 (number 6), SCL
  @{ */
#define BOARD_INITPINS_SCL_PORT PORTE /*!<@brief PORT device name: PORTE */
#define BOARD_INITPINS_SCL_PIN 19U    /*!<@brief PORTE pin index: 19 */
                                      /* @} */

/*! @name PORTA0 (number 12), SWD_CLK
  @{ */
#define BOARD_INITPINS_SWD_CLK_PORT PORTA /*!<@brief PORT device name: PORTA */
#define BOARD_INITPINS_SWD_CLK_PIN 0U     /*!<@brief PORTA pin index: 0 */
                                          /* @} */

/*! @name PORTA3 (number 15), SWD_DIO
  @{ */
#define BOARD_INITPINS_SWD_DIO_PORT PORTA /*!<@brief PORT device name: PORTA */
#define BOARD_INITPINS_SWD_DIO_PIN 3U     /*!<@brief PORTA pin index: 3 */
                                          /* @} */

/*! @name PORTA4 (number 16), OPEN
  @{ */
#define BOARD_INITPINS_OPEN_GPIO GPIOA /*!<@brief GPIO device name: GPIOA */
#define BOARD_INITPINS_OPEN_PORT PORTA /*!<@brief PORT device name: PORTA */
#define BOARD_INITPINS_OPEN_PIN 4U     /*!<@brief PORTA pin index: 4 */
                                       /* @} */

/*! @name PORTA18 (number 17), EXTAL
  @{ */
#define BOARD_INITPINS_EXTAL_PORT PORTA /*!<@brief PORT device name: PORTA */
#define BOARD_INITPINS_EXTAL_PIN 18U    /*!<@brief PORTA pin index: 18 */
                                        /* @} */

/*! @name PORTA19 (number 18), XTAL
  @{ */
#define BOARD_INITPINS_XTAL_PORT PORTA /*!<@brief PORT device name: PORTA */
#define BOARD_INITPINS_XTAL_PIN 19U    /*!<@brief PORTA pin index: 19 */
                                       /* @} */

/*! @name PORTA20 (number 19), RESET
  @{ */
#define BOARD_INITPINS_RESET_PORT PORTA /*!<@brief PORT device name: PORTA */
#define BOARD_INITPINS_RESET_PIN 20U    /*!<@brief PORTA pin index: 20 */
                                        /* @} */

/*! @name PORTC2 (number 23), TP7
  @{ */
#define BOARD_INITPINS_TP7_GPIO GPIOC /*!<@brief GPIO device name: GPIOC */
#define BOARD_INITPINS_TP7_PORT PORTC /*!<@brief PORT device name: PORTC */
#define BOARD_INITPINS_TP7_PIN 2U     /*!<@brief PORTC pin index: 2 */
                                      /* @} */

/*! @name PORTC4 (number 25), TP6
  @{ */
#define BOARD_INITPINS_TP6_GPIO GPIOC /*!<@brief GPIO device name: GPIOC */
#define BOARD_INITPINS_TP6_PORT PORTC /*!<@brief PORT device name: PORTC */
#define BOARD_INITPINS_TP6_PIN 4U     /*!<@brief PORTC pin index: 4 */
                                      /* @} */

/*! @name PORTC5 (number 26), TP5
  @{ */
#define BOARD_INITPINS_TP5_GPIO GPIOC /*!<@brief GPIO device name: GPIOC */
#define BOARD_INITPINS_TP5_PORT PORTC /*!<@brief PORT device name: PORTC */
#define BOARD_INITPINS_TP5_PIN 5U     /*!<@brief PORTC pin index: 5 */
                                      /* @} */

/*! @name PORTC6 (number 27), UART_RX
  @{ */
#define BOARD_INITPINS_UART_RX_PORT PORTC /*!<@brief PORT device name: PORTC */
#define BOARD_INITPINS_UART_RX_PIN 6U     /*!<@brief PORTC pin index: 6 */
                                          /* @} */

/*! @name PORTC7 (number 28), UART_TX
  @{ */
#define BOARD_INITPINS_UART_TX_PORT PORTC /*!<@brief PORT device name: PORTC */
#define BOARD_INITPINS_UART_TX_PIN 7U     /*!<@brief PORTC pin index: 7 */
                                          /* @} */

/*! @name PORTB0 (number 20), CH6_DIM
  @{ */
#define BOARD_INITPINS_CH6_DIM_PORT PORTB /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_CH6_DIM_PIN 0U     /*!<@brief PORTB pin index: 0 */
                                          /* @} */

/*! @name PORTC1 (number 22), TP9
  @{ */
#define BOARD_INITPINS_TP9_GPIO GPIOC /*!<@brief GPIO device name: GPIOC */
#define BOARD_INITPINS_TP9_PORT PORTC /*!<@brief PORT device name: PORTC */
#define BOARD_INITPINS_TP9_PIN 1U     /*!<@brief PORTC pin index: 1 */
                                      /* @} */

/*! @name PORTE24 (number 10), CH2_DIM
  @{ */
#define BOARD_INITPINS_CH2_DIM_PORT PORTE /*!<@brief PORT device name: PORTE */
#define BOARD_INITPINS_CH2_DIM_PIN 24U    /*!<@brief PORTE pin index: 24 */
                                          /* @} */

/*! @name PORTE25 (number 11), CH3_DIM
  @{ */
#define BOARD_INITPINS_CH3_DIM_PORT PORTE /*!<@brief PORT device name: PORTE */
#define BOARD_INITPINS_CH3_DIM_PIN 25U    /*!<@brief PORTE pin index: 25 */
                                          /* @} */

/*! @name PORTA1 (number 13), CH4_DIM
  @{ */
#define BOARD_INITPINS_CH4_DIM_PORT PORTA /*!<@brief PORT device name: PORTA */
#define BOARD_INITPINS_CH4_DIM_PIN 1U     /*!<@brief PORTA pin index: 1 */
                                          /* @} */

/*! @name PORTA2 (number 14), CH5_DIM
  @{ */
#define BOARD_INITPINS_CH5_DIM_PORT PORTA /*!<@brief PORT device name: PORTA */
#define BOARD_INITPINS_CH5_DIM_PIN 2U     /*!<@brief PORTA pin index: 2 */
                                          /* @} */

/*! @name PORTB1 (number 21), CH7_DIM
  @{ */
#define BOARD_INITPINS_CH7_DIM_PORT PORTB /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_CH7_DIM_PIN 1U     /*!<@brief PORTB pin index: 1 */
                                          /* @} */

/*! @name PORTC3 (number 24), CH8_DIM
  @{ */
#define BOARD_INITPINS_CH8_DIM_PORT PORTC /*!<@brief PORT device name: PORTC */
#define BOARD_INITPINS_CH8_DIM_PIN 3U     /*!<@brief PORTC pin index: 3 */
                                          /* @} */

/*! @name PORTD4 (number 29), CH9_DIM
  @{ */
#define BOARD_INITPINS_CH9_DIM_PORT PORTD /*!<@brief PORT device name: PORTD */
#define BOARD_INITPINS_CH9_DIM_PIN 4U     /*!<@brief PORTD pin index: 4 */
                                          /* @} */

/*! @name PORTD5 (number 30), CH10_DIM
  @{ */
#define BOARD_INITPINS_CH10_DIM_PORT PORTD /*!<@brief PORT device name: PORTD */
#define BOARD_INITPINS_CH10_DIM_PIN 5U     /*!<@brief PORTD pin index: 5 */
                                           /* @} */

/*! @name PORTD6 (number 31), CH11_DIM
  @{ */
#define BOARD_INITPINS_CH11_DIM_PORT PORTD /*!<@brief PORT device name: PORTD */
#define BOARD_INITPINS_CH11_DIM_PIN 6U     /*!<@brief PORTD pin index: 6 */
                                           /* @} */

/*! @name PORTD7 (number 32), CH12_DIM
  @{ */
#define BOARD_INITPINS_CH12_DIM_PORT PORTD /*!<@brief PORT device name: PORTD */
#define BOARD_INITPINS_CH12_DIM_PIN 7U     /*!<@brief PORTD pin index: 7 */
                                           /* @} */

/*! @name PORTE30 (number 9), CH1_DIM
  @{ */
#define BOARD_INITPINS_CH1_DIM_PORT PORTE /*!<@brief PORT device name: PORTE */
#define BOARD_INITPINS_CH1_DIM_PIN 30U    /*!<@brief PORTE pin index: 30 */
                                          /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void);

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
