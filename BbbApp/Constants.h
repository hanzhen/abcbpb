//
//  constants.h
//  BbbApp
//
//  Created by Harry Layman on 10/21/12.
//  Copyright (c) 2012 Harry Layman. All rights reserved.
//

#ifndef BbbApp_constants_h
#define BbbApp_constants_h


/* 

 
 ver 81 121113am
 
 ABC:
 
 letter tabs, colorized letter done. new images done.
 
 
 datbase errors:
 
 a.  open, onion, orange, oil.  fix these. some wrong data.
 b.  vegitarian misspelling in one of 3 V words.
 c.  fix up foreign words for quick, zipper, xylophone.  check others.
 d.  about page.
 e.  second language processing.
    tile words loaded in arrays.
 
 1) add lang2 words to string if Lang2 is ON and non-english.
 2) fix setting of Lang2 on, saving it, 
 3) remove romanization stuff -- all.
 
 
 
 */

//  secondLangPref
#define kFirstLangChoice    @"L1Choice" //  NOT USED. ONLY ENglish as first language!
#define	kSecondLangChoice	@"L2Choice"	//
#define	kPhoneLang	@"PHLang"	//

#define kL1RomanizationChoice   @"L1RChoice"    //
#define	kL2RomanizationChoice	@"L2RChoice"	//


#define	kLanguageLabels	@"K1LangLabels"	//  -- set in NSUserDefaults by view did load for kL1
// database file name only here
#define kSoftwareVersion @"version 1.10" //  121102 1247PM // shown on about page  -- with romanization...
#define kDatabaseVersion @"databaseVersionKey" //
// shown on about page

#define kWLURL  @"http://www.wordzlianxi.com"

#define kDatabaseNameLW @"ABCV101K2.sl3"   //


#define kCN 0
#define kDE 1
#define kEN 2
#define kES 3
#define kFR 4
#define kIT 5
#define kJP 6
#define kKR 7
#define kRU 8
#define kPT 9

#define kBlack 0  // K
#define kRed 1    // R
#define kBlue 2   // U
#define kGreen 3  // G

#define kBlackSTR @"K"  // 0
#define kRedSTR @"R"    // 1
#define kBlueSTR @"U"   // 2
#define kGreenSTR @"G"  // 3


#define	kLES	@"ES"

#define	kLEN	@"EN"

#define	kLCN	@"CN" // fix! 121102

#define	kLIT	@"IT"

#define	kLDE	@"DE"

#define	kLFR 	@"FR"

#define	kLKR 	@"KR"

#define	kLJP 	@"JP"



#endif
