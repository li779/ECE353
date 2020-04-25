// Copyright (c) 2015-16, Joe Krachey
// All rights reserved.
//
// Redistribution and use in source or binary form, with or without modification, 
// are permitted provided that the following conditions are met:
//
// 1. Redistributions in source form must reproduce the above copyright 
//    notice, this list of conditions and the following disclaimer in 
//    the documentation and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR 
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; 
// OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, 
// EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

/* 
**  Image data
*/

#include "images.h"

// 
//  Image data for player_front
// 

// 
//  Image data for player2
// 

const uint8_t easytank_upBitmaps[] =
{
		0x00, 0x00, 0x00, 0x00, 0x00, //                                       
	0x00, 0x00, 0x00, 0x00, 0x00, //                                       
	0x00, 0x00, 0x00, 0x00, 0x00, //                                       
	0x00, 0x00, 0xF8, 0x00, 0x00, //                 #####                 
	0x00, 0x00, 0xF8, 0x00, 0x00, //                 #####                 
	0x00, 0x00, 0xF8, 0x00, 0x00, //                 #####                 
	0x00, 0x00, 0xF8, 0x00, 0x00, //                 #####                 
	0x00, 0x00, 0x70, 0x00, 0x00, //                  ###                  
	0x00, 0x00, 0x70, 0x00, 0x00, //                  ###                  
	0x00, 0x00, 0x70, 0x00, 0x00, //                  ###                  
	0x00, 0x00, 0x70, 0x00, 0x00, //                  ###                  
	0x00, 0x00, 0x70, 0x00, 0x00, //                  ###                  
	0x00, 0x00, 0x70, 0x00, 0x00, //                  ###                  
	0x0F, 0xFF, 0xFF, 0xFF, 0x80, //     #############################     
	0x0F, 0xF0, 0x70, 0x7F, 0x80, //     ########     ###     ########     
	0x0F, 0xF0, 0x70, 0x7F, 0x80, //     ########     ###     ########     
	0x0F, 0xF0, 0x70, 0x7F, 0x80, //     ########     ###     ########     
	0x08, 0x30, 0x70, 0x40, 0x80, //     #     ##     ###     #      #     
	0x0F, 0xF0, 0x70, 0x7F, 0x80, //     ########     ###     ########     
	0x0F, 0xF0, 0x70, 0x7F, 0x80, //     ########     ###     ########     
	0x0F, 0xF0, 0x70, 0x7F, 0x80, //     ########     ###     ########     
	0x0F, 0xF0, 0x70, 0x7F, 0x80, //     ########     ###     ########     
	0x0F, 0xF0, 0x70, 0x7F, 0x80, //     ########     ###     ########     
	0x0F, 0xF0, 0x70, 0x7F, 0x80, //     ########     ###     ########     
	0x0F, 0xF1, 0xFC, 0x7F, 0x80, //     ########   #######   ########     
	0x0F, 0xF7, 0x06, 0x7F, 0x80, //     ######## ###     ##  ########     
	0x0C, 0x36, 0x03, 0x61, 0x80, //     ##    ## ##       ## ##    ##     
	0x0F, 0xFC, 0x01, 0x7F, 0x80, //     ##########         # ########     
	0x0F, 0xFD, 0xFF, 0xFF, 0x80, //     ########## ##################     
	0x0F, 0xFB, 0x7B, 0xFF, 0x80, //     ######### ## #### ###########     
	0x0F, 0xFB, 0xFF, 0xFF, 0x80, //     ######### ###################     
	0x08, 0x3D, 0xCF, 0xC1, 0x80, //     #     #### ###  ######     ##     
	0x0F, 0xFC, 0x01, 0x7F, 0x80, //     ##########         # ########     
	0x0F, 0xF4, 0x03, 0x7F, 0x80, //     ######## #        ## ########     
	0x0F, 0xF6, 0x06, 0x7F, 0x80, //     ######## ##      ##  ########     
	0x0F, 0xF3, 0x9E, 0x7F, 0x80, //     ########  ###  ####  ########     
	0x08, 0x30, 0xF8, 0x40, 0x80, //     #     ##    #####    #      #     
	0x0F, 0xFF, 0xFF, 0xFF, 0x80, //     #############################     
	0x00, 0x00, 0x00, 0x00, 0x00, //                                       
	0x00, 0x00, 0x00, 0x00, 0x00, //                                       
	0x00, 0x00, 0x00, 0x00, 0x00, //                                       
	0x00, 0x00, 0x00, 0x00, 0x00, //                                       
};

// Bitmap sizes for player2
const uint8_t easytank_upWidthPixels = 38;
const uint8_t easytank_upHeightPixels = 42;


// 
//  Image data for easytank
// 

const uint8_t easytank_downBitmaps[] =
{
	0x00, 0x00, 0x00, 0x00, 0x00, //                                       
	0x00, 0x00, 0x00, 0x00, 0x00, //                                       
	0x00, 0x00, 0x00, 0x00, 0x00, //                                       
	0x00, 0x00, 0x00, 0x00, 0x00, //                                       
	0x0F, 0xFF, 0xFF, 0xFF, 0x80, //     #############################     
	0x08, 0x30, 0xF8, 0x40, 0x80, //     #     ##    #####    #      #     
	0x0F, 0xF3, 0x9E, 0x7F, 0x80, //     ########  ###  ####  ########     
	0x0F, 0xF6, 0x06, 0x7F, 0x80, //     ######## ##      ##  ########     
	0x0F, 0xF4, 0x03, 0x7F, 0x80, //     ######## #        ## ########     
	0x0F, 0xFC, 0x01, 0x7F, 0x80, //     ##########         # ########     
	0x08, 0x3D, 0xCF, 0xC1, 0x80, //     #     #### ###  ######     ##     
	0x0F, 0xFB, 0xFF, 0xFF, 0x80, //     ######### ###################     
	0x0F, 0xFB, 0x7B, 0xFF, 0x80, //     ######### ## #### ###########     
	0x0F, 0xFD, 0xFF, 0xFF, 0x80, //     ########## ##################     
	0x0F, 0xFC, 0x01, 0x7F, 0x80, //     ##########         # ########     
	0x0C, 0x36, 0x03, 0x61, 0x80, //     ##    ## ##       ## ##    ##     
	0x0F, 0xF7, 0x06, 0x7F, 0x80, //     ######## ###     ##  ########     
	0x0F, 0xF1, 0xFC, 0x7F, 0x80, //     ########   #######   ########     
	0x0F, 0xF0, 0x70, 0x7F, 0x80, //     ########     ###     ########     
	0x0F, 0xF0, 0x70, 0x7F, 0x80, //     ########     ###     ########     
	0x0F, 0xF0, 0x70, 0x7F, 0x80, //     ########     ###     ########     
	0x0F, 0xF0, 0x70, 0x7F, 0x80, //     ########     ###     ########     
	0x0F, 0xF0, 0x70, 0x7F, 0x80, //     ########     ###     ########     
	0x0F, 0xF0, 0x70, 0x7F, 0x80, //     ########     ###     ########     
	0x08, 0x30, 0x70, 0x40, 0x80, //     #     ##     ###     #      #     
	0x0F, 0xF0, 0x70, 0x7F, 0x80, //     ########     ###     ########     
	0x0F, 0xF0, 0x70, 0x7F, 0x80, //     ########     ###     ########     
	0x0F, 0xF0, 0x70, 0x7F, 0x80, //     ########     ###     ########     
	0x0F, 0xFF, 0xFF, 0xFF, 0x80, //     #############################     
	0x00, 0x00, 0x70, 0x00, 0x00, //                  ###                  
	0x00, 0x00, 0x70, 0x00, 0x00, //                  ###                  
	0x00, 0x00, 0x70, 0x00, 0x00, //                  ###                  
	0x00, 0x00, 0x70, 0x00, 0x00, //                  ###                  
	0x00, 0x00, 0x70, 0x00, 0x00, //                  ###                  
	0x00, 0x00, 0x70, 0x00, 0x00, //                  ###                  
	0x00, 0x00, 0xF8, 0x00, 0x00, //                 #####                 
	0x00, 0x00, 0xF8, 0x00, 0x00, //                 #####                 
	0x00, 0x00, 0xF8, 0x00, 0x00, //                 #####                 
	0x00, 0x00, 0xF8, 0x00, 0x00, //                 #####                 
	0x00, 0x00, 0x00, 0x00, 0x00, //                                       
	0x00, 0x00, 0x00, 0x00, 0x00, //                                       
	0x00, 0x00, 0x00, 0x00, 0x00, //                                       
};

// Bitmap sizes for easytank
const uint8_t easytank_downWidthPixels = 38;
const uint8_t easytank_downHeightPixels = 42;

// 
//  Image data for easytank_right
// 

const uint8_t easytank_rightBitmaps[] =
{
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //                                           
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //                                           
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //                                           
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //                                           
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //                                           
	0x0F, 0xFF, 0xFF, 0xF8, 0x00, 0x00, //     #########################             
	0x0B, 0xFF, 0xFF, 0x78, 0x00, 0x00, //     # ################## ####             
	0x0B, 0xDE, 0xFF, 0x78, 0x00, 0x00, //     # #### #### ######## ####             
	0x0B, 0xDE, 0xFF, 0x78, 0x00, 0x00, //     # #### #### ######## ####             
	0x0B, 0xDE, 0xFF, 0x78, 0x00, 0x00, //     # #### #### ######## ####             
	0x0B, 0xDE, 0xFF, 0x78, 0x00, 0x00, //     # #### #### ######## ####             
	0x0B, 0xDF, 0xFF, 0x78, 0x00, 0x00, //     # #### ############# ####             
	0x0F, 0xFF, 0xFF, 0xF8, 0x00, 0x00, //     #########################             
	0x08, 0x3C, 0x00, 0x08, 0x00, 0x00, //     #     ####              #             
	0x08, 0xFF, 0x00, 0x08, 0x00, 0x00, //     #   ########            #             
	0x0B, 0xBD, 0x80, 0x08, 0x00, 0x00, //     # ### #### ##           #             
	0x0B, 0x34, 0xC0, 0x08, 0x00, 0x00, //     # ##  ## #  ##          #             
	0x0E, 0x3C, 0x40, 0x08, 0x1E, 0x00, //     ###   ####   #          #      ####   
	0x0E, 0x1C, 0x7F, 0xFF, 0xFE, 0x00, //     ###    ###   ######################   
	0x0C, 0x1C, 0x7F, 0xFF, 0xFE, 0x00, //     ##     ###   ######################   
	0x0C, 0x3C, 0x7F, 0xFF, 0xFE, 0x00, //     ##    ####   ######################   
	0x0E, 0x34, 0x40, 0x08, 0x1E, 0x00, //     ###   ## #   #          #      ####   
	0x0A, 0x3C, 0xC0, 0x08, 0x00, 0x00, //     # #   ####  ##          #             
	0x0B, 0x19, 0x80, 0x08, 0x00, 0x00, //     # ##   ##  ##           #             
	0x09, 0xE7, 0x80, 0x08, 0x00, 0x00, //     #  ####  ####           #             
	0x08, 0x7E, 0x00, 0x08, 0x00, 0x00, //     #    ######             #             
	0x0F, 0xFF, 0xFF, 0xF8, 0x00, 0x00, //     #########################             
	0x0F, 0xFF, 0xFF, 0xF8, 0x00, 0x00, //     #########################             
	0x0B, 0xDE, 0xFF, 0x78, 0x00, 0x00, //     # #### #### ######## ####             
	0x0B, 0xDE, 0xFF, 0x78, 0x00, 0x00, //     # #### #### ######## ####             
	0x0B, 0xDE, 0xFF, 0x78, 0x00, 0x00, //     # #### #### ######## ####             
	0x0B, 0xDE, 0xFF, 0x78, 0x00, 0x00, //     # #### #### ######## ####             
	0x0B, 0xDF, 0xFF, 0x78, 0x00, 0x00, //     # #### ############# ####             
	0x0F, 0xFF, 0xFF, 0xF8, 0x00, 0x00, //     #########################             
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //                                           
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //                                           
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //                                           
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //                                           
};

// Bitmap sizes for easytank_right
const uint8_t easytank_rightWidthPixels = 42;
const uint8_t easytank_rightHeightPixels = 38;

// 
//  Image data for easytank_right
// 

const uint8_t easytank_leftBitmaps[] =
{
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //                                           
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //                                           
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //                                           
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //                                           
	0x00, 0x07, 0xFF, 0xFF, 0xFC, 0x00, //              #########################    
	0x00, 0x07, 0xBF, 0xFE, 0xF4, 0x00, //              #### ############# #### #    
	0x00, 0x07, 0xBF, 0xDE, 0xF4, 0x00, //              #### ######## #### #### #    
	0x00, 0x07, 0xBF, 0xDE, 0xF4, 0x00, //              #### ######## #### #### #    
	0x00, 0x07, 0xBF, 0xDE, 0xF4, 0x00, //              #### ######## #### #### #    
	0x00, 0x07, 0xBF, 0xDE, 0xF4, 0x00, //              #### ######## #### #### #    
	0x00, 0x07, 0xFF, 0xFF, 0xFC, 0x00, //              #########################    
	0x00, 0x07, 0xFF, 0xFF, 0xFC, 0x00, //              #########################    
	0x00, 0x04, 0x00, 0x1F, 0x84, 0x00, //              #             ######    #    
	0x00, 0x04, 0x00, 0x79, 0xE4, 0x00, //              #           ####  ####  #    
	0x00, 0x04, 0x00, 0x66, 0x34, 0x00, //              #           ##  ##   ## #    
	0x00, 0x04, 0x00, 0xCF, 0x14, 0x00, //              #          ##  ####   # #    
	0x1E, 0x04, 0x00, 0x8B, 0x1C, 0x00, //    ####      #          #   # ##   ###    
	0x1F, 0xFF, 0xFF, 0x8F, 0x0C, 0x00, //    ######################   ####    ##    
	0x1F, 0xFF, 0xFF, 0x8E, 0x0C, 0x00, //    ######################   ###     ##    
	0x1F, 0xFF, 0xFF, 0x8E, 0x1C, 0x00, //    ######################   ###    ###    
	0x1E, 0x04, 0x00, 0x8F, 0x1C, 0x00, //    ####      #          #   ####   ###    
	0x00, 0x04, 0x00, 0xCB, 0x34, 0x00, //              #          ##  # ##  ## #    
	0x00, 0x04, 0x00, 0x6F, 0x74, 0x00, //              #           ## #### ### #    
	0x00, 0x04, 0x00, 0x3F, 0xC4, 0x00, //              #            ########   #    
	0x00, 0x04, 0x00, 0x0F, 0x04, 0x00, //              #              ####     #    
	0x00, 0x07, 0xFF, 0xFF, 0xFC, 0x00, //              #########################    
	0x00, 0x07, 0xBF, 0xFE, 0xF4, 0x00, //              #### ############# #### #    
	0x00, 0x07, 0xBF, 0xDE, 0xF4, 0x00, //              #### ######## #### #### #    
	0x00, 0x07, 0xBF, 0xDE, 0xF4, 0x00, //              #### ######## #### #### #    
	0x00, 0x07, 0xBF, 0xDE, 0xF4, 0x00, //              #### ######## #### #### #    
	0x00, 0x07, 0xBF, 0xDE, 0xF4, 0x00, //              #### ######## #### #### #    
	0x00, 0x07, 0xBF, 0xFF, 0xF4, 0x00, //              #### ################## #    
	0x00, 0x07, 0xFF, 0xFF, 0xFC, 0x00, //              #########################    
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //                                           
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //                                           
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //                                           
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //                                           
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //                                           
};

// Bitmap sizes for easytank_right
const uint8_t easytank_leftWidthPixels = 42;
const uint8_t easytank_leftHeightPixels = 38;



// 
//  Image data for panzer_II
// 

const uint8_t panzer_II_upBitmaps[] =
{
	0x00, 0x00, 0x00, //                     
	0x00, 0x60, 0x00, //          ##         
	0x00, 0x60, 0x00, //          ##         
	0x00, 0x60, 0x00, //          ##         
	0x0C, 0x63, 0x80, //     ##   ##   ###   
	0x17, 0xFE, 0x80, //    # ########## #   
	0x1C, 0x61, 0x80, //    ###   ##    ##   
	0x14, 0x62, 0x80, //    # #   ##   # #   
	0x1C, 0x63, 0x80, //    ###   ##   ###   
	0x15, 0xFA, 0x80, //    # # ###### # #   
	0x1C, 0x93, 0x80, //    ###  #  #  ###   
	0x14, 0x92, 0x80, //    # #  #  #  # #   
	0x1C, 0xF3, 0x80, //    ###  ####  ###   
	0x14, 0x02, 0x80, //    # #        # #   
	0x1C, 0x03, 0x80, //    ###        ###   
	0x17, 0xFE, 0x80, //    # ########## #   
	0x1C, 0x03, 0x80, //    ###        ###   
	0x00, 0x00, 0x00, //                     
	0x00, 0x00, 0x00, //                     
	0x00, 0x00, 0x00, //                     
};

// Bitmap sizes for panzer_II
const uint8_t panzer_II_upWidthPixels = 20;
const uint8_t panzer_II_upHeightPixels = 20;

// 
//  Image data for panzer_II
// 

const uint8_t panzer_II_downBitmaps[] =
{
	0x00, 0x00, 0x00, //                     
	0x00, 0x00, 0x00, //                     
	0x00, 0x00, 0x00, //                     
	0x1C, 0x03, 0x80, //    ###        ###   
	0x17, 0xFE, 0x80, //    # ########## #   
	0x1C, 0x03, 0x80, //    ###        ###   
	0x14, 0x02, 0x80, //    # #        # #   
	0x1C, 0xF3, 0x80, //    ###  ####  ###   
	0x14, 0x92, 0x80, //    # #  #  #  # #   
	0x1C, 0x93, 0x80, //    ###  #  #  ###   
	0x15, 0xFA, 0x80, //    # # ###### # #   
	0x1C, 0x63, 0x80, //    ###   ##   ###   
	0x14, 0x62, 0x80, //    # #   ##   # #   
	0x1C, 0x61, 0x80, //    ###   ##    ##   
	0x17, 0xFE, 0x80, //    # ########## #   
	0x0C, 0x63, 0x80, //     ##   ##   ###   
	0x00, 0x60, 0x00, //          ##         
	0x00, 0x60, 0x00, //          ##         
	0x00, 0x60, 0x00, //          ##         
	0x00, 0x00, 0x00, //                     
};

// Bitmap sizes for panzer_II
const uint8_t panzer_II_downWidthPixels = 20;
const uint8_t panzer_II_downHeightPixels = 20;

// 
//  Image data for panzer_II_right
// 

const uint8_t panzer_II_rightBitmaps[] =
{
	0x00, 0x00, 0x00, //                     
	0x00, 0x00, 0x00, //                     
	0x00, 0x00, 0x00, //                     
	0x1F, 0xFF, 0x00, //    #############    
	0x15, 0x55, 0x00, //    # # # # # # #    
	0x1F, 0xFB, 0x00, //    ########## ##    
	0x08, 0x02, 0x00, //     #         #     
	0x08, 0x22, 0x00, //     #     #   #     
	0x09, 0xE2, 0x00, //     #  ####   #     
	0x09, 0x3F, 0xE0, //     #  #  ######### 
	0x09, 0x3F, 0xE0, //     #  #  ######### 
	0x09, 0xE2, 0x00, //     #  ####   #     
	0x08, 0x22, 0x00, //     #     #   #     
	0x08, 0x02, 0x00, //     #         #     
	0x1F, 0xFF, 0x00, //    #############    
	0x15, 0x55, 0x00, //    # # # # # # #    
	0x1F, 0xFE, 0x00, //    ############     
	0x00, 0x00, 0x00, //                     
	0x00, 0x00, 0x00, //                     
	0x00, 0x00, 0x00, //                     
};

// Bitmap sizes for panzer_II_right
const uint8_t panzer_II_rightWidthPixels = 20;
const uint8_t panzer_II_rightHeightPixels = 20;

// 
//  Image data for panzer_II_right
// 

const uint8_t panzer_II_leftBitmaps[] =
{
	0x00, 0x00, 0x00, //                     
	0x00, 0x00, 0x00, //                     
	0x00, 0x00, 0x00, //                     
	0x07, 0xFF, 0x80, //      ############   
	0x0A, 0xAA, 0x80, //     # # # # # # #   
	0x0F, 0xFF, 0x80, //     #############   
	0x04, 0x01, 0x00, //      #         #    
	0x04, 0x41, 0x00, //      #   #     #    
	0x04, 0x79, 0x00, //      #   ####  #    
	0x7F, 0xC9, 0x00, //  #########  #  #    
	0x7F, 0xC9, 0x00, //  #########  #  #    
	0x04, 0x79, 0x00, //      #   ####  #    
	0x04, 0x41, 0x00, //      #   #     #    
	0x04, 0x01, 0x00, //      #         #    
	0x0D, 0xFF, 0x80, //     ## ##########   
	0x0A, 0xAA, 0x80, //     # # # # # # #   
	0x0F, 0xFF, 0x80, //     #############   
	0x00, 0x00, 0x00, //                     
	0x00, 0x00, 0x00, //                     
	0x00, 0x00, 0x00, //                     
};

// Bitmap sizes for panzer_II_right
const uint8_t panzer_II_leftWidthPixels = 20;
const uint8_t panzer_II_leftHeightPixels = 20;

/* 
**  Image data for panzer_IV_up
*/

const uint8_t panzer_IV_upBitmaps[] =
{
	0x00, 0x00, 0x00, //                     
	0x00, 0x60, 0x00, //          ##         
	0x00, 0x60, 0x00, //          ##         
	0x00, 0x60, 0x00, //          ##         
	0x1C, 0x63, 0x80, //    ###   ##   ###   
	0x17, 0xFE, 0x80, //    # ########## #   
	0x1C, 0x63, 0x80, //    ###   ##   ###   
	0x14, 0x62, 0x80, //    # #   ##   # #   
	0x19, 0xFB, 0x80, //    ##  ###### ###   
	0x15, 0x0A, 0x80, //    # # #    # # #   
	0x1D, 0x0B, 0x80, //    ### #    # ###   
	0x15, 0x4A, 0x80, //    # # # #  # # #   
	0x1D, 0x0B, 0x80, //    ### #    # ###   
	0x10, 0x12, 0x80, //    #       #  # #   
	0x18, 0x03, 0x80, //    ##         ###   
	0x17, 0xFE, 0x80, //    # ########## #   
	0x1C, 0x03, 0x80, //    ###        ###   
	0x00, 0x00, 0x00, //                     
	0x00, 0x00, 0x00, //                     
	0x00, 0x00, 0x00, //                     
};

/* Bitmap sizes for panzer_IV_up */
const uint8_t panzer_IV_upWidthPixels = 20;
const uint8_t panzer_IV_upHeightPixels = 20;

/* 
**  Image data for panzer_IV_right
*/

const uint8_t panzer_IV_rightBitmaps[] =
{
	0x00, 0x00, 0x00, //                     
	0x00, 0x00, 0x00, //                     
	0x00, 0x00, 0x00, //                     
	0x1F, 0xFF, 0x00, //    #############    
	0x15, 0x55, 0x00, //    # # # # # # #    
	0x19, 0xEF, 0x00, //    ##  #### ####    
	0x08, 0x02, 0x00, //     #         #     
	0x09, 0xF2, 0x00, //     #  #####  #     
	0x08, 0x12, 0x00, //     #      #  #     
	0x08, 0x9F, 0xE0, //     #   #  ######## 
	0x08, 0x1F, 0xE0, //     #      ######## 
	0x0A, 0x12, 0x00, //     # #    #  #     
	0x09, 0xF2, 0x00, //     #  #####  #     
	0x08, 0x02, 0x00, //     #         #     
	0x1F, 0xFF, 0x00, //    #############    
	0x15, 0x55, 0x00, //    # # # # # # #    
	0x1F, 0xFF, 0x00, //    #############    
	0x00, 0x00, 0x00, //                     
	0x00, 0x00, 0x00, //                     
	0x00, 0x00, 0x00, //                     
};

/* Bitmap sizes for panzer_IV_right */
const uint8_t panzer_IV_rightWidthPixels = 20;
const uint8_t panzer_IV_rightHeightPixels = 20;

/* 
**  Image data for panzer_IV_down
*/

const uint8_t panzer_IV_downBitmaps[] =
{
	0x00, 0x00, 0x00, //                     
	0x00, 0x00, 0x00, //                     
	0x00, 0x00, 0x00, //                     
	0x1C, 0x03, 0x80, //    ###        ###   
	0x17, 0xFE, 0x80, //    # ########## #   
	0x1C, 0x01, 0x80, //    ###         ##   
	0x14, 0x80, 0x80, //    # #  #       #   
	0x1D, 0x0B, 0x80, //    ### #    # ###   
	0x15, 0x2A, 0x80, //    # # #  # # # #   
	0x1D, 0x0B, 0x80, //    ### #    # ###   
	0x15, 0x0A, 0x80, //    # # #    # # #   
	0x1D, 0xF9, 0x80, //    ### ######  ##   
	0x14, 0x62, 0x80, //    # #   ##   # #   
	0x1C, 0x63, 0x80, //    ###   ##   ###   
	0x17, 0xFE, 0x80, //    # ########## #   
	0x1C, 0x63, 0x80, //    ###   ##   ###   
	0x00, 0x60, 0x00, //          ##         
	0x00, 0x60, 0x00, //          ##         
	0x00, 0x60, 0x00, //          ##         
	0x00, 0x00, 0x00, //                     
};

/* Bitmap sizes for panzer_IV_down */
const uint8_t panzer_IV_downWidthPixels = 20;
const uint8_t panzer_IV_downHeightPixels = 20;

/* 
**  Image data for panzer_IV_left
*/

const uint8_t panzer_IV_leftBitmaps[] =
{
	0x00, 0x00, 0x00, //                     
	0x00, 0x00, 0x00, //                     
	0x00, 0x00, 0x00, //                     
	0x0F, 0xFF, 0x80, //     #############   
	0x0A, 0xAA, 0x80, //     # # # # # # #   
	0x0F, 0xFF, 0x80, //     #############   
	0x04, 0x01, 0x00, //      #         #    
	0x04, 0xF9, 0x00, //      #  #####  #    
	0x04, 0x85, 0x00, //      #  #    # #    
	0x7F, 0x81, 0x00, //  ########      #    
	0x7F, 0x91, 0x00, //  ########  #   #    
	0x04, 0x81, 0x00, //      #  #      #    
	0x04, 0xF9, 0x00, //      #  #####  #    
	0x04, 0x01, 0x00, //      #         #    
	0x0F, 0x79, 0x80, //     #### ####  ##   
	0x0A, 0xAA, 0x80, //     # # # # # # #   
	0x0F, 0xFF, 0x80, //     #############   
	0x00, 0x00, 0x00, //                     
	0x00, 0x00, 0x00, //                     
	0x00, 0x00, 0x00, //                     
};

/* Bitmap sizes for panzer_IV_left */
const uint8_t panzer_IV_leftWidthPixels = 20;
const uint8_t panzer_IV_leftHeightPixels = 20;

/* 
**  Image data for panzer_VI_up
*/

const uint8_t panzer_VI_upBitmaps[] =
{
	0x00, 0x60, 0x00, //          ##         
	0x38, 0x61, 0xC0, //   ###    ##    ###  
	0x2F, 0xFF, 0x40, //   # ############ #  
	0x38, 0x61, 0xC0, //   ###    ##    ###  
	0x2F, 0xFF, 0x40, //   # ############ #  
	0x38, 0x61, 0xC0, //   ###    ##    ###  
	0x28, 0x61, 0x40, //   # #    ##    # #  
	0x39, 0xF9, 0xC0, //   ###  ######  ###  
	0x2B, 0x05, 0x40, //   # # ##     # # #  
	0x3E, 0x07, 0xC0, //   #####      #####  
	0x2C, 0x03, 0x40, //   # ##        ## #  
	0x3C, 0x03, 0xC0, //   ####        ####  
	0x2E, 0x87, 0x40, //   # ### #    ### #  
	0x3B, 0x0D, 0xC0, //   ### ##    ## ###  
	0x29, 0x39, 0x40, //   # #  #  ###  # #  
	0x38, 0x91, 0xC0, //   ###   #  #   ###  
	0x28, 0xF1, 0x40, //   # #   ####   # #  
	0x38, 0x01, 0xC0, //   ###          ###  
	0x2F, 0xFF, 0x40, //   # ############ #  
	0x39, 0x99, 0xC0, //   ###  ##  ##  ###  
};

/* Bitmap sizes for panzer_VI_up */
const uint8_t panzer_VI_upWidthPixels = 20;
const uint8_t panzer_VI_upHeightPixels = 20;

/* 
**  Image data for panzer_VI_right
*/

const uint8_t panzer_VI_rightBitmaps[] =
{
	0x00, 0x00, 0x00, //                     
	0x00, 0x00, 0x00, //                     
	0xFF, 0xFF, 0xE0, // ################### 
	0xAA, 0xAA, 0xA0, // # # # # # # # # # # 
	0xFF, 0xFF, 0xE0, // ################### 
	0x41, 0xE1, 0x40, //  #     ####    # #  
	0x43, 0x31, 0x40, //  #    ##  ##   # #  
	0xC6, 0x19, 0x40, // ##   ##    ##  # #  
	0xD9, 0x09, 0x40, // ## ##  #    #  # #  
	0x50, 0x0F, 0xF0, //  # #        ########
	0x54, 0x0F, 0xF0, //  # # #      ########
	0xDC, 0x09, 0x40, // ## ###      #  # #  
	0xC6, 0x09, 0x40, // ##   ##     #  # #  
	0x43, 0x31, 0x40, //  #    ##  ##   # #  
	0x41, 0xE1, 0x40, //  #     ####    # #  
	0xFF, 0xFF, 0xE0, // ################### 
	0xAA, 0xAA, 0xA0, // # # # # # # # # # # 
	0xFF, 0xFF, 0xE0, // ################### 
	0x00, 0x00, 0x00, //                     
	0x00, 0x00, 0x00, //                     
};

/* Bitmap sizes for panzer_VI_right */
const uint8_t panzer_VI_rightWidthPixels = 20;
const uint8_t panzer_VI_rightHeightPixels = 20;

/* 
**  Image data for panzer_VI_down
*/

const uint8_t panzer_VI_downBitmaps[] =
{
	0x39, 0x99, 0xC0, //   ###  ##  ##  ###  
	0x2F, 0xFF, 0x40, //   # ############ #  
	0x38, 0x01, 0xC0, //   ###          ###  
	0x28, 0xF1, 0x40, //   # #   ####   # #  
	0x38, 0x91, 0xC0, //   ###   #  #   ###  
	0x29, 0xC9, 0x40, //   # #  ###  #  # #  
	0x3B, 0x0D, 0xC0, //   ### ##    ## ###  
	0x2E, 0x17, 0x40, //   # ###    # ### #  
	0x3C, 0x03, 0xC0, //   ####        ####  
	0x2C, 0x03, 0x40, //   # ##        ## #  
	0x3E, 0x07, 0xC0, //   #####      #####  
	0x2A, 0x0D, 0x40, //   # # #     ## # #  
	0x39, 0xF9, 0xC0, //   ###  ######  ###  
	0x28, 0x61, 0x40, //   # #    ##    # #  
	0x38, 0x61, 0xC0, //   ###    ##    ###  
	0x2F, 0xFF, 0x40, //   # ############ #  
	0x38, 0x61, 0xC0, //   ###    ##    ###  
	0x2F, 0xFF, 0x40, //   # ############ #  
	0x38, 0x61, 0xC0, //   ###    ##    ###  
	0x00, 0x60, 0x00, //          ##         
};

/* Bitmap sizes for panzer_VI_down */
const uint8_t panzer_VI_downWidthPixels = 20;
const uint8_t panzer_VI_downHeightPixels = 20;

/* 
**  Image data for panzer_VI_left
*/

const uint8_t panzer_VI_leftBitmaps[] =
{
	0x00, 0x00, 0x00, //                     
	0x00, 0x00, 0x00, //                     
	0x7F, 0xFF, 0xF0, //  ###################
	0x55, 0x55, 0x50, //  # # # # # # # # # #
	0x7F, 0xFF, 0xF0, //  ###################
	0x28, 0x78, 0x20, //   # #    ####     # 
	0x28, 0xCC, 0x20, //   # #   ##  ##    # 
	0x29, 0x06, 0x30, //   # #  #     ##   ##
	0x29, 0x03, 0xB0, //   # #  #      ### ##
	0xFF, 0x02, 0xA0, // ########      # # # 
	0xFF, 0x00, 0xA0, // ########        # # 
	0x29, 0x09, 0xB0, //   # #  #    #  ## ##
	0x29, 0x86, 0x30, //   # #  ##    ##   ##
	0x28, 0xCC, 0x20, //   # #   ##  ##    # 
	0x28, 0x78, 0x20, //   # #    ####     # 
	0x7F, 0xFF, 0xF0, //  ###################
	0x55, 0x55, 0x50, //  # # # # # # # # # #
	0x7F, 0xFF, 0xF0, //  ###################
	0x00, 0x00, 0x00, //                     
	0x00, 0x00, 0x00, //                     
};

/* Bitmap sizes for panzer_VI_left */
const uint8_t panzer_VI_leftWidthPixels = 20;
const uint8_t panzer_VI_leftHeightPixels = 20;

// 
//  Image data for shell_obj
// 

const uint8_t shell_objBitmaps[] =
{
	0x00,
	0x60, // ##
	0x60, // ##
	0x00
};

// Bitmap sizes for shell_obj
const uint8_t shell_objWidthPixels = 4;
const uint8_t shell_objHeightPixels = 4;