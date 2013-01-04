//
//  BixiCity.m
//  Bicyclette
//
//  Created by Nicolas on 15/12/12.
//  Copyright (c) 2012 Nicolas Bouilleaud. All rights reserved.
//

#import "XMLCityWithStationDataInSubnodes.h"
#import "BicycletteCity.mogenerated.h"

/****************************************************************************/
#pragma mark -

@interface BixiCity : _XMLCityWithStationDataInSubnodes <XMLCityWithStationDataInSubnodes>
@end

@implementation BixiCity

#pragma mark City Data Update

- (BOOL) hasRegions
{
    return NO;
}

- (NSDictionary*) KVCMapping
{
    return @{@"id" : StationAttributes.number,
             @"name" : StationAttributes.name,
             @"lat" : StationAttributes.latitude,
             @"long": StationAttributes.longitude,
             @"nbBikes": StationAttributes.status_available,
             @"nbEmptyDocks": StationAttributes.status_free,
             };
}

- (NSString*) stationElementName
{
    return @"station";
}

@end
