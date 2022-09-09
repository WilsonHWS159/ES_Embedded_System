.section .vector_table

.word _msp_init
.word reset_handler

/*********************************************************/

.weak	nmi_handler
.thumb_set	nmi_handler,default_handler
.word nmi_handler

/*********************************************************/

.weak	hardfault_handler
.thumb_set	hardfault_handler,default_handler
.word hardfault_handler

/*********************************************************/

.weak	mmfault_handler
.thumb_set	mmfault_handler,default_handler
.word mmfault_handler

/*********************************************************/

.weak	busfault_handler
.thumb_set	busfault_handler,default_handler
.word busfault_handler

/*********************************************************/

.weak	usagefault_handler
.thumb_set	usagefault_handler,default_handler
.word usagefault_handler

/*********************************************************/

.word 0 //reserved
.word 0 //reserved
.word 0 //reserved
.word 0 //reserved

/*********************************************************/

.weak	svc_handler
.thumb_set	svc_handler,default_handler
.word svc_handler

/*********************************************************/

.weak	debugmonitor_handler
.thumb_set	debugmonitor_handler,default_handler
.word debugmonitor_handler

/*********************************************************/

.word 0 //reserved

/*********************************************************/

.weak	pendsv_handler
.thumb_set	pendsv_handler,default_handler
.word pendsv_handler

/*********************************************************/

.weak	systick_handler
.thumb_set	systick_handler,default_handler
.word systick_handler

/*********************************************************/

//IRQ 0
.weak	wwdg_handler
.thumb_set	wwdg_handler,default_handler
.word wwdg_handler

/*********************************************************/

//IRQ 1
.weak	pvd_handler
.thumb_set	pvd_handler,default_handler
.word pvd_handler

/*********************************************************/

//IRQ 2
.weak	tamp_stamp_handler
.thumb_set	tamp_stamp_handler,default_handler
.word tamp_stamp_handler

/*********************************************************/

//IRQ 3
.weak	rtc_wkup_handler
.thumb_set	rtc_wkup_handler,default_handler
.word rtc_wkup_handler

/*********************************************************/

//IRQ 4
.weak	flash_handler
.thumb_set	flash_handler,default_handler
.word flash_handler

/*********************************************************/

//IRQ 5
.weak	rcc_handler
.thumb_set	rcc_handler,default_handler
.word rcc_handler

/*********************************************************/

//IRQ 6
.weak	exti0_handler
.thumb_set	exti0_handler,default_handler
.word exti0_handler

/*********************************************************/

//IRQ 7
.weak	exti1_handler
.thumb_set	exti1_handler,default_handler
.word exti1_handler

/*********************************************************/

//IRQ 8
.weak	exti2_handler
.thumb_set	exti2_handler,default_handler
.word exti2_handler

/*********************************************************/

//IRQ 9
.weak	exti3_handler
.thumb_set	exti3_handler,default_handler
.word exti3_handler

/*********************************************************/

//IRQ 10
.weak	exti4_handler
.thumb_set	exti4_handler,default_handler
.word exti4_handler

/*********************************************************/

//IRQ 11
.weak	dma1_stream0_handler
.thumb_set	dma1_stream0_handler,default_handler
.word dma1_stream0_handler

/*********************************************************/

//IRQ 12
.weak	dma1_stream1_handler
.thumb_set	dma1_stream1_handler,default_handler
.word dma1_stream1_handler

/*********************************************************/

//IRQ 13
.weak	dma1_stream2_handler
.thumb_set	dma1_stream2_handler,default_handler
.word dma1_stream2_handler

/*********************************************************/

//IRQ 14
.weak	dma1_stream3_handler
.thumb_set	dma1_stream3_handler,default_handler
.word dma1_stream3_handler

/*********************************************************/

//IRQ 15
.weak	dma1_stream4_handler
.thumb_set	dma1_stream4_handler,default_handler
.word dma1_stream4_handler

/*********************************************************/

//IRQ 16
.weak	dma1_stream5_handler
.thumb_set	dma1_stream5_handler,default_handler
.word dma1_stream5_handler

/*********************************************************/

//IRQ 17
.weak	dma1_stream6_handler
.thumb_set	dma1_stream6_handler,default_handler
.word dma1_stream6_handler

/*********************************************************/

//IRQ 18
.weak	adc_handler
.thumb_set	adc_handler,default_handler
.word adc_handler

/*********************************************************/

//IRQ 19
.weak	can1_tx_handler
.thumb_set	can1_tx_handler,default_handler
.word can1_tx_handler

/*********************************************************/

//IRQ 20
.weak	can1_rx0_handler
.thumb_set	can1_rx0_handler,default_handler
.word can1_rx0_handler

/*********************************************************/

//IRQ 21
.weak	can1_rx1_handler
.thumb_set	can1_rx1_handler,default_handler
.word can1_rx1_handler

/*********************************************************/

//IRQ 22
.weak	can1_sce_handler
.thumb_set	can1_sce_handler,default_handler
.word can1_sce_handler

/*********************************************************/

//IRQ 23
.weak	exti9_5_handler
.thumb_set	exti9_5_handler,default_handler
.word exti9_5_handler

/*********************************************************/

//IRQ 24
.weak	tim1_brk_tim9_handler
.thumb_set	tim1_brk_tim9_handler,default_handler
.word tim1_brk_tim9_handler

/*********************************************************/

//IRQ 25
.weak	tim1_up_tim10_handler
.thumb_set	tim1_up_tim10_handler,default_handler
.word tim1_up_tim10_handler

/*********************************************************/

//IRQ 26
.weak	tim1_trg_com_tim11_handler
.thumb_set	tim1_trg_com_tim11_handler,default_handler
.word tim1_trg_com_tim11_handler

/*********************************************************/

//IRQ 27
.weak	tim1_cc_handler
.thumb_set	tim1_cc_handler,default_handler
.word tim1_cc_handler

/*********************************************************/

//IRQ 28
.weak	tim2_handler
.thumb_set	tim2_handler,default_handler
.word tim2_handler

/*********************************************************/

//IRQ 29
.weak	tim3_handler
.thumb_set	tim3_handler,default_handler
.word tim3_handler

/*********************************************************/

//IRQ 30
.weak	tim4_handler
.thumb_set	tim4_handler,default_handler
.word tim4_handler

/*********************************************************/

//IRQ 31
.weak	i2c1_ev_handler
.thumb_set	i2c1_ev_handler,default_handler
.word i2c1_ev_handler

/*********************************************************/

//IRQ 32
.weak	i2c1_er_handler
.thumb_set	i2c1_er_handler,default_handler
.word i2c1_er_handler

/*********************************************************/

//IRQ 33
.weak	i2c2_ev_handler
.thumb_set	i2c2_ev_handler,default_handler
.word i2c2_ev_handler

/*********************************************************/

//IRQ 34
.weak	i2c2_er_handler
.thumb_set	i2c2_er_handler,default_handler
.word i2c2_er_handler

/*********************************************************/

//IRQ 35
.weak	spi1_handler
.thumb_set	spi1_handler,default_handler
.word spi1_handler

/*********************************************************/

//IRQ 36
.weak	spi2_handler
.thumb_set	spi2_handler,default_handler
.word spi2_handler

/*********************************************************/

//IRQ 37
.weak	usart1_handler
.thumb_set	usart1_handler,default_handler
.word usart1_handler

/*********************************************************/

//IRQ 38
.weak	usart2_handler
.thumb_set	usart2_handler,default_handler
.word usart2_handler

/*********************************************************/

//IRQ 39
.weak	usart3_handler
.thumb_set	usart3_handler,default_handler
.word usart3_handler

/*********************************************************/

//IRQ 40
.weak	exti15_10_handler
.thumb_set	exti15_10_handler,default_handler
.word exti15_10_handler

/*********************************************************/

//IRQ 41
.weak	rtc_alarm_handler
.thumb_set	rtc_alarm_handler,default_handler
.word rtc_alarm_handler

/*********************************************************/

//IRQ 42
.weak	otg_fs_wkup_handler
.thumb_set	otg_fs_wkup_handler,default_handler
.word otg_fs_wkup_handler

/*********************************************************/

//IRQ 43
.weak	tim8_brk_tim12_handler
.thumb_set	tim8_brk_tim12_handler,default_handler
.word tim8_brk_tim12_handler

/*********************************************************/

//IRQ 44
.weak	tim8_up_tim13_handler
.thumb_set	tim8_up_tim13_handler,default_handler
.word tim8_up_tim13_handler

/*********************************************************/

//IRQ 45
.weak	tim8_trg_com_tim14_handler
.thumb_set	tim8_trg_com_tim14_handler,default_handler
.word tim8_trg_com_tim14_handler

/*********************************************************/

//IRQ 46
.weak	tim8_cc_handler
.thumb_set	tim8_cc_handler,default_handler
.word tim8_cc_handler

/*********************************************************/

//IRQ 47
.weak	dma1_stream7_handler
.thumb_set	dma1_stream7_handler,default_handler
.word dma1_stream7_handler

/*********************************************************/

//IRQ 48
.weak	fsmc_handler
.thumb_set	fsmc_handler,default_handler
.word fsmc_handler

/*********************************************************/

//IRQ 49
.weak	sdio_handler
.thumb_set	sdio_handler,default_handler
.word sdio_handler

/*********************************************************/

//IRQ 50
.weak	tim5_handler
.thumb_set	tim5_handler,default_handler
.word tim5_handler

/*********************************************************/

//IRQ 51
.weak	spi3_handler
.thumb_set	spi3_handler,default_handler
.word spi3_handler

/*********************************************************/

//IRQ 52
.weak	uart4_handler
.thumb_set	uart4_handler,default_handler
.word uart4_handler

/*********************************************************/

//IRQ 53
.weak	uart5_handler
.thumb_set	uart5_handler,default_handler
.word uart5_handler

/*********************************************************/

//IRQ 54
.weak	tim6_dac_handler
.thumb_set	tim6_dac_handler,default_handler
.word tim6_dac_handler

/*********************************************************/

//IRQ 55
.weak	tim7_handler
.thumb_set	tim7_handler,default_handler
.word tim7_handler

/*********************************************************/

//IRQ 56
.weak	dma2_stream0_handler
.thumb_set	dma2_stream0_handler,default_handler
.word dma2_stream0_handler

/*********************************************************/

//IRQ 57
.weak	dma2_stream1_handler
.thumb_set	dma2_stream1_handler,default_handler
.word dma2_stream1_handler

/*********************************************************/

//IRQ 58
.weak	dma2_stream2_handler
.thumb_set	dma2_stream2_handler,default_handler
.word dma2_stream2_handler

/*********************************************************/

//IRQ 59
.weak	dma2_stream3_handler
.thumb_set	dma2_stream3_handler,default_handler
.word dma2_stream3_handler

/*********************************************************/

//IRQ 60
.weak	dma2_stream4_handler
.thumb_set	dma2_stream4_handler,default_handler
.word dma2_stream4_handler

/*********************************************************/

//IRQ 61
.weak	eth_handler
.thumb_set	eth_handler,default_handler
.word eth_handler

/*********************************************************/

//IRQ 62
.weak	eth_wkup_handler
.thumb_set	eth_wkup_handler,default_handler
.word eth_wkup_handler

/*********************************************************/

//IRQ 63
.weak	can2_tx_handler
.thumb_set	can2_tx_handler,default_handler
.word can2_tx_handler

/*********************************************************/

//IRQ 64
.weak	can2_rx0_handler
.thumb_set	can2_rx0_handler,default_handler
.word can2_rx0_handler

/*********************************************************/

//IRQ 65
.weak	can2_rx1_handler
.thumb_set	can2_rx1_handler,default_handler
.word can2_rx1_handler

/*********************************************************/

//IRQ 66
.weak	can2_sce_handler
.thumb_set	can2_sce_handler,default_handler
.word can2_sce_handler

/*********************************************************/

//IRQ 67
.weak	otg_fs_handler
.thumb_set	otg_fs_handler,default_handler
.word otg_fs_handler


/*********************************************************/

//IRQ 68
.weak	dma2_stream5_handler
.thumb_set	dma2_stream5_handler,default_handler
.word dma2_stream5_handler


/*********************************************************/

//IRQ 69
.weak	dma2_stream6_handler
.thumb_set	dma2_stream6_handler,default_handler
.word dma2_stream6_handler


/*********************************************************/

//IRQ 70
.weak	dma2_stream7_handler
.thumb_set	dma2_stream7_handler,default_handler
.word dma2_stream7_handler

/*********************************************************/

//IRQ 71
.weak	usart6_handler
.thumb_set	usart6_handler,default_handler
.word usart6_handler

/*********************************************************/

//IRQ 72
.weak	i2c3_ev_handler
.thumb_set	i2c3_ev_handler,default_handler
.word i2c3_ev_handler

/*********************************************************/

//IRQ 73
.weak	i2c3_er_handler
.thumb_set	i2c3_er_handler,default_handler
.word i2c3_er_handler

/*********************************************************/

//IRQ 74
.weak	otg_hs_ep1_out_handler
.thumb_set	otg_hs_ep1_out_handler,default_handler
.word otg_hs_ep1_out_handler

/*********************************************************/

//IRQ 75
.weak	otg_hs_ep1_in_handler
.thumb_set	otg_hs_ep1_in_handler,default_handler
.word otg_hs_ep1_in_handler


/*********************************************************/

//IRQ 76
.weak	otg_hs_wkup_handler
.thumb_set	otg_hs_wkup_handler,default_handler
.word otg_hs_wkup_handler

/*********************************************************/

//IRQ 77
.weak	otg_hs_handler
.thumb_set	otg_hs_handler,default_handler
.word otg_hs_handler

/*********************************************************/

//IRQ 78
.weak	dcmi_handler
.thumb_set	dcmi_handler,default_handler
.word dcmi_handler

/*********************************************************/

//IRQ 79
.weak	cryp_handler
.thumb_set	cryp_handler,default_handler
.word cryp_handler

/*********************************************************/

//IRQ 80
.weak	hash_rng_handler
.thumb_set	hash_rng_handler,default_handler
.word hash_rng_handler

/*********************************************************/

//IRQ 81
.weak	fpu_handler
.thumb_set	fpu_handler,default_handler
.word fpu_handler

//////////////////////////////////////////////////////////

.syntax unified

.type	default_handler, %function
default_handler:
	b	.
