//
//  BbbAppViewController.h
//  BbbApp
//
//  Created by Harry Layman on 10/20/12.
//  Copyright (c) 2012 Harry Layman. All rights reserved.
//
//
/*
 
 NSArray pageContent will provide an ordered list of NSStrings, one per page in the book.
 
 Thie pageContent array will be (re-)built from scratch each time the game loads; it will not run in the background. it could be built each time the settings are changed (to a new second language, for example).
 
 GLOBAL Data:
 
 this is going to be engish only abc letter game in round one.
 
 db has more stuff in it but only get list of letter-pictures-and-words -- 70 items, at least one for each of 26 letters.
 
 
 
 Array:  Tiles
 
 70 tiles with PicPicImageNM for each tile's picture, plus 8 tileTXT fields and tileNM for CN, JP and KR/ txt and 3  fields, on for each language.
 
 I will only use picture file name, english TXT to put on page, and use the setID and letterNO to order them (so get A1, A2, A3, B1, B2, C1, D1, D2, D3, etc.) 
 
 
 Array:  Sets
 
no sets. the string value for setID is the letter, and the new title line will say A-B-C Letter Game: Letter A where the final "A" is the "setID" value (a string, not a number that has to be decoded to a language specific set name...)
 
 
 
 Array:  Version (same)
 
 1 record.  used on about page to get global database version var
 
 in view did load, we do onetime load of database (with switch to prevent reloading).
 
 then in createPageContent we build that NSArray from the global database table loaded arrays.
 
 
 */


// remaining work 121110 -- need to create new method to "get letter N" in addition to forward and reverse tab. remove skip forward, skip back. -- or make a and z.

#import <UIKit/UIKit.h>
#import "ContentViewController.h"

#import <sqlite3.h> // 100905 import sqlite framework

//@class SoundEffect;

@interface BbbAppViewController : UIViewController
<UIPageViewControllerDataSource, UIPageViewControllerDelegate, PageControlDelegate> {

    NSString *k_L2;  // used with NSDefaults;
    NSString *k_L1;  // also settable....
    NSString *k_LPhone; // save phone lang setting for labels on settings page. ignore l1 / l2 choices.
    
    NSString *L1String_Setting;
    NSString *L2String_Setting;
    NSString *LPhoneString_Setting;
    
    BOOL bL1R; // not used.
    BOOL bL2R; // append romanization if JP, CN, KR for L1 and L2 -- settings. -- only settable via settings. but use if set.
    
    NSString *databaseName, *databasePath;	//100905
    
    int userLangIDX, secondLangIDX;
    int kL1, kL2;   // values of user language, 2nd language
    int kLPhone;    // value for language of phone.
    int tileCNT;
    
    // used with NSDefaults
    

    
    BOOL bShowRomanization;
    BOOL hasLoadedDB;
    
#define TILESTBLSIZE 90   // only 70 rows in ver 1.00   one each for Q, U, X and Z.    26x3 = 78, less (4 * 2)
#define TILES_PERPAGE  3  // put in implementation file. for abc letter game... 
   
//  ARRAYs TO HOLD SETNAME

    NSString *setNM_CN[20], *setNM_DE[20], *setNM_EN[20], *setNM_ES[20];
    NSString *setNM_FR[20], *setNM_IT[20], *setNM_JP[20], *setNM_KR[20];
    
    
//  ARRAYs TO HOLD language NAMEs    
    NSString *langNM_CN[20], *langNM_DE[20], *langNM_EN[20], *langNM_ES[20];
    NSString *langNM_FR[20], *langNM_IT[20], *langNM_JP[20], *langNM_KR[20];
    NSString *secondLang[20];
    
    NSMutableString *settingsLabelDelimitedStringHolder;
    
// alloc NSMutableString in m file for this puprose...
    // make single string, tack onto end of NSArray, send to content view controller --
    //      hich will pass it to settingsPopoverViewcontroller if called....
    
    
    NSMutableString *setNMPart1, *txtWordL1, *txtWordL2;
    NSMutableString *currentLetterNM;
    
//    NSMutableString *currentContentPageString;
    
    NSString *pageWordString;
    

    int      setID[20];  // should just hold 1 to 16 -- in element zero to 15.
    
    int     langID[20];  // should hold first 8 values for active languages 1 to 8.
    
    int gMaxSet, gMaxLang; // plan for 0 through 15
    int tilesPerPage; //  = TILES_PERPAGE;
    

    
    
    NSString *tilePicPicImageNM_db[TILESTBLSIZE]; // picture representing the word
    int tileSetID_db[TILESTBLSIZE];         // set containing this word
    int tileID_db[TILESTBLSIZE];   // serno
    int tileSetIDX[TILESTBLSIZE];  // 1 to 26
    
    
    NSString *tileSetNM [TILESTBLSIZE];         //  contains "A", "B", etc
    NSString *tileLetterTXT [TILESTBLSIZE];     //  contains "Aa", "Bb", etc.

    
	NSString *tileTXT_cn[TILESTBLSIZE];     //
    NSString *tileTXT_de[TILESTBLSIZE];     //
    NSString *tileTXT_en[TILESTBLSIZE];     //
    NSString *tileTXT_es[TILESTBLSIZE];     //

    NSString *tileTXT_fr[TILESTBLSIZE];     //
    NSString *tileTXT_it[TILESTBLSIZE];     //
    NSString *tileTXT_jp[TILESTBLSIZE];     //
    NSString *tileTXT_kr[TILESTBLSIZE];     //

	NSString *tileNM_cn[TILESTBLSIZE];     //
    NSString *tileNM_jp[TILESTBLSIZE];     //
    NSString *tileNM_kr[TILESTBLSIZE];     //

    

    NSString *color_de[TILESTBLSIZE];     //
    NSString *color_es[TILESTBLSIZE];     //    
    NSString *color_fr[TILESTBLSIZE];     //
    NSString *color_it[TILESTBLSIZE];     //
    
    
    
    }



@property (strong, nonatomic) NSString *L2String_Setting;
@property (strong, nonatomic) NSString *L1String_Setting;
@property (strong, nonatomic) NSString *LPhoneString_Setting;

@property (strong, nonatomic) UIPageViewController *pageController;
@property (strong, nonatomic) NSArray *pageContent;
@property (readwrite, nonatomic) NSUInteger currentIndex;

// @property (strong, nonatomic) NSArray *pageContent2;
// this pageContent2 will be image file names and lable text -- now using the original array (name)with new string of my values..

- (void) updateCurrentIndex;
- (void) backwardTap:(id)sender;
- (void) forwardTap:(id)sender;
- (void) prevTap:(id)sender;
- (void) nextTap:(id)sender;
- (void) turnToPage:(id)sender toPage:(int)pageNBR;


@end
