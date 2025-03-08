// Copyright 2022 UNN-CS
#include <cstdint>
#include "tasks.h"

double calculateGapSize() {
  double EarthRadius = 6378100.0;
  Circle roap(EarthRadius);
  roap.setFerence(roap.getFerence() + 1);
  return roap.getRadius() - EarthRadius;
}

double calculatePoolCost() {
  Circle pool(3);
  Circle pool_with_track(4);
  return 1000 * (pool_with_track.getArea() - pool.getArea()) 
    + 2000 * pool_with_track.getFerence();
}
