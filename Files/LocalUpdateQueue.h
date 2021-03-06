//
//  LocalUpdateQueue.h
//  Bicyclette
//
//  Created by Nicolas Bouilleaud on 16/07/12.
//  Copyright (c) 2012 Nicolas Bouilleaud. All rights reserved.
//

//
// Locatable
@protocol Locatable <NSObject>
- (CLLocation *) location;
@optional
- (CLLocationDistance) radius;
@end

//
// Update Group
@protocol LocalUpdateGroup <NSObject, Locatable>
@property (readonly) NSArray * pointsToUpdate;
@end

//
// Update Point
@protocol LocalUpdatePoint <NSObject, Locatable>
@required
- (void) updateWithCompletionBlock:(void(^)(NSError* error))completion;
@optional
@property BOOL queuedForUpdate;
@end

//
// Collections
@interface NSArray (Locatable)
- (instancetype) filteredArrayWithinDistance:(CLLocationDistance)distance fromLocation:(CLLocation*)location;
- (instancetype) sortedArrayByDistanceFromLocation:(CLLocation*)location;
// Not strictly the nearest : the locatables' radius is used to weigh in favor of the larger objects.
- (id<Locatable>) nearestLocatableFrom:(CLLocation*)location;
@end


@protocol LocalUpdateQueueDelegate;

//
// Queue
@interface LocalUpdateQueue : NSObject
@property (nonatomic) CLLocation * referenceLocation;
- (void) setReferenceLocation:(CLLocation *)referenceLocation andStartIfNecessary:(BOOL)startIfNecessary_;
@property NSTimeInterval delayBetweenPointUpdates;

// Monitored Update Groups
@property (nonatomic) CLLocationDistance moniteredGroupsMaximumDistance;
@property (nonatomic) BOOL monitoringPaused;
- (void) addMonitoredGroup:(NSObject<LocalUpdateGroup>*)group;
- (void) removeMonitoredGroup:(NSObject<LocalUpdateGroup>*)group;

// One-shot Update Groups
- (void) addOneshotGroup:(NSObject<LocalUpdateGroup>*)group;
- (void) removeOneshotGroup:(NSObject<LocalUpdateGroup>*)group;

@property (weak) id<LocalUpdateQueueDelegate> delegate;

- (void) buildUpdateQueue;

@end

//
// delegate
@protocol LocalUpdateQueueDelegate <NSObject>
- (void) updateQueue:(LocalUpdateQueue *)queue didUpdateOneshotPoint:(id<LocalUpdatePoint>)point ofGroup:(id<LocalUpdateGroup>)group;
- (void) updateQueueDidComplete:(LocalUpdateQueue *)queue;
@end

