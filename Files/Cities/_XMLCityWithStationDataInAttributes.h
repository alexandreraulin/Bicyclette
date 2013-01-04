//
//  _XMLCityWithStationDataInAttributes.h
//  Bicyclette
//
//  Created by Nicolas on 04/01/13.
//  Copyright (c) 2013 Nicolas Bouilleaud. All rights reserved.
//

#import "BicycletteCity.h"

@interface _XMLCityWithStationDataInAttributes : _BicycletteCity
- (void) parseData:(NSData *)data
     fromURLString:(NSString*)urlString
         inContext:(NSManagedObjectContext*)context
       oldStations:(NSMutableArray*)oldStations;
@end

// To be implemented by subclasses
@protocol XMLCityWithStationDataInAttributes <BicycletteCity>
- (NSString*) stationElementName;
- (NSString*) stationNumberFromStationValues:(NSDictionary*)values;
- (NSDictionary*) KVCMapping;
@end
