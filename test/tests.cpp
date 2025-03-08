// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cstdint>
#include "circle.h"
#include "tasks.h"

TEST(CircleCreationCheck, defaultCircleCreation) {
  EXPECT_NO_THROW(Circle circle);
}

TEST(CircleCreationCheck, circleCreationWithZeroRadius) {
  EXPECT_NO_THROW(Circle circle(0.0));
}

TEST(CircleCreationCheck, circleCreationWithNegativeRadius) {
  EXPECT_ANY_THROW(Circle circle(-13.0));
}

TEST(CircleCreationCheck, circleCreationWithPositiveRadius) {
  EXPECT_NO_THROW(Circle circle(13.0));
}

TEST(CircleCreationCheck, circleCreationWithRadius13) {
  Circle circle(13.0);
  EXPECT_NEAR(circle.getRadius(), 13.0, 1e-6);
  EXPECT_NEAR(circle.getFerence(), 13.0 * 2 * pi, 1e-6);
  EXPECT_NEAR(circle.getArea(), 13.0 * 13.0 * pi, 1e-6);
}

TEST(CircleRadiusChangeCheck, setZeroRadius) {
  Circle circle(13.0);
  circle.setRadius(0.0);
  EXPECT_DOUBLE_EQ(circle.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(circle.getFerence(), 0.0);
  EXPECT_DOUBLE_EQ(circle.getArea(), 0.0);
}

TEST(CircleRadiusChangeCheck, setNegativeRadius) {
  Circle circle(13.0);
  EXPECT_ANY_THROW(circle.setRadius(-13.0));
}

TEST(CircleRadiusChangeCheck, setPositiveRadius1) {
  Circle circle(13.0);
  circle.setRadius(1.0);
  EXPECT_NEAR(circle.getRadius(), 1.0, 1e-6);
  EXPECT_NEAR(circle.getFerence(), 2 * pi, 1e-6);
  EXPECT_NEAR(circle.getArea(), pi, 1e-6);
}

TEST(CircleRadiusChangeCheck, setPositiveRadius13) {
  Circle circle(1.0);
  circle.setRadius(13.0);
  EXPECT_NEAR(circle.getRadius(), 13.0, 1e-6);
  EXPECT_NEAR(circle.getFerence(), 13.0 * 2 * pi, 1e-6);
  EXPECT_NEAR(circle.getArea(), 13.0 * 13.0 * pi, 1e-6);
}

TEST(CircleRadiusChangeCheck, setPositiveRadius1000) {
  Circle circle(1.0);
  circle.setRadius(1000.0);
  EXPECT_NEAR(circle.getRadius(), 1000.0, 1e-6);
  EXPECT_NEAR(circle.getFerence(), 1000.0 * 2 * pi, 1e-6);
  EXPECT_NEAR(circle.getArea(), 1000.0 * 1000.0 * pi, 1e-6);
}

TEST(CircleFerenceChangeCheck, setZeroFerence) {
  Circle circle(13.0);
  circle.setFerence(0.0);
  EXPECT_DOUBLE_EQ(circle.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(circle.getFerence(), 0.0);
  EXPECT_DOUBLE_EQ(circle.getArea(), 0.0);
}

TEST(CircleFerenceChangeCheck, setNegativeFerence) {
  Circle circle(13.0);
  EXPECT_ANY_THROW(circle.setFerence(-13.0));
}

TEST(CircleFerenceChangeCheck, setPositiveFerence2Pi) {
  Circle circle(13.0);
  circle.setFerence(2 * pi);
  EXPECT_NEAR(circle.getRadius(), 1.0, 1e-6);
  EXPECT_NEAR(circle.getFerence(), 2 * pi, 1e-6);
  EXPECT_NEAR(circle.getArea(), pi, 1e-6);
}

TEST(CircleFerenceChangeCheck, setPositiveFerence13) {
  Circle circle(1.0);
  circle.setFerence(13.0);
  EXPECT_NEAR(circle.getRadius(), 13.0 / (2 * pi), 1e-6);
  EXPECT_NEAR(circle.getFerence(), 13.0, 1e-6);
  EXPECT_NEAR(circle.getArea(), 13.0 * 13.0 / (4 * pi), 1e-6);
}

TEST(CircleFerenceChangeCheck, setPositiveFerence1000) {
  Circle circle(1.0);
  circle.setFerence(1000.0);
  EXPECT_NEAR(circle.getRadius(), 1000.0 / (2 * pi), 1e-6);
  EXPECT_NEAR(circle.getFerence(), 1000.0, 1e-6);
  EXPECT_NEAR(circle.getArea(), 1000.0 * 1000.0 / (4 * pi), 1e-6);
}

TEST(CircleAreaChangeCheck, setZeroArea) {
  Circle circle(13.0);
  circle.setArea(0.0);
  EXPECT_DOUBLE_EQ(circle.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(circle.getFerence(), 0.0);
  EXPECT_DOUBLE_EQ(circle.getArea(), 0.0);
}

TEST(CircleAreaChangeCheck, setNegativeArea) {
  Circle circle(13.0);
  EXPECT_ANY_THROW(circle.setArea(-13.0));
}

TEST(CircleAreaChangeCheck, setPositiveAreaPi) {
  Circle circle(13.0);
  circle.setArea(pi);
  EXPECT_NEAR(circle.getRadius(), 1.0, 1e-6);
  EXPECT_NEAR(circle.getFerence(), 2 * pi, 1e-6);
  EXPECT_NEAR(circle.getArea(), pi, 1e-6);
}

TEST(CircleAreaChangeCheck, setPositiveArea13) {
  Circle circle(1.0);
  circle.setArea(13.0);
  EXPECT_NEAR(circle.getRadius(), sqrt(13 / pi), 1e-6);
  EXPECT_NEAR(circle.getFerence(), sqrt(13 / pi) * 2 * pi, 1e-6);
  EXPECT_NEAR(circle.getArea(), 13, 1e-6);
}

TEST(CircleAreaChangeCheck, setPositiveArea1000) {
  Circle circle(1.0);
  circle.setArea(1000.0);
  EXPECT_NEAR(circle.getRadius(), sqrt(1000 / pi), 1e-6);
  EXPECT_NEAR(circle.getFerence(), sqrt(1000 / pi) * 2 * pi, 1e-6);
  EXPECT_NEAR(circle.getArea(), 1000, 1e-6);
}

TEST(TasksCheck, gapSizeTask) {
  EXPECT_NEAR(calculateGapSize(), 0.159155, 1e-6);
}

TEST(TasksCheck, poolCostTask) {
  EXPECT_NEAR(calculatePoolCost(), 72256.6, 1e-6);
}
