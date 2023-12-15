#include "gtest/gtest.h"
#include "Queue.hpp"

class QueueTests : public ::testing::Test {
protected:
    Queue<int> queue{};
    int element{};
};

// primero() y ultimo() queda probado.
TEST_F(QueueTests, Add) {
    queue.add(2);
    EXPECT_EQ(queue.first(), 2);
    EXPECT_EQ(queue.last(), 2);

    queue.add(1);
    queue.add(3);
    EXPECT_EQ(queue.first(), 2);
    EXPECT_EQ(queue.last(), 3);
}

TEST_F(QueueTests, Remove) {
    queue.add(1);
    queue.add(3);

    element = queue.remove();
    EXPECT_EQ(element, 1);
    EXPECT_EQ(queue.first(), 3);
    EXPECT_EQ(queue.last(), 3);
}

TEST_F(QueueTests, RemoveHannlesEmptyQueue) {
    EXPECT_THROW(queue.remove(), EmptyException);
}

TEST_F(QueueTests, Empty) {
    EXPECT_TRUE(queue.empty());

    queue.add(1);
    EXPECT_FALSE(queue.empty());

    queue.remove();
    EXPECT_TRUE(queue.empty());
}

TEST_F(QueueTests, Size) {
    EXPECT_EQ(queue.size(), 0);

    queue.add(1);
    queue.add(2);
    queue.add(3);
    EXPECT_EQ(queue.size(), 3);

    queue.remove();
    EXPECT_EQ(queue.size(), 2);
}

TEST_F(QueueTests, FirstHandlesEmptyQueue) {
    EXPECT_THROW(queue.first(), EmptyException);
}

TEST_F(QueueTests, LastHandlesEmptyQueue) {
    EXPECT_THROW(queue.last(), EmptyException);
}