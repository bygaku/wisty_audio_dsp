//
// Created by intwi on 2025/12/31.
//

#include <gtest/gtest.h>
#include "buffer/ring_buffer.h"

using wwist::audio::buffer::RingBuffer;
using wwist::audio::buffer::MakeRingBuffer;

// TEST float buffer.
TEST(RingBufferTest, MakeRingBufferFloat) {
	constexpr int capacity = 512;
	auto buf = MakeRingBuffer<float>(capacity);

	EXPECT_EQ(buf.capacity, capacity);

	EXPECT_EQ(static_cast<int>(buf.data.size()), capacity);

	EXPECT_EQ(buf.read_pos, 0);

	for (int i = 0; i < capacity; ++i) {
		EXPECT_FLOAT_EQ(buf.data[static_cast<std::size_t>(i)], 0.0f);
	}
}

// TEST short buffer.
TEST(RingBufferTest, MakeRingBufferShort) {
	constexpr int capacity = 512;

	auto buf = MakeRingBuffer<short>(capacity);

	EXPECT_EQ(buf.capacity, capacity);

	EXPECT_EQ(static_cast<int>(buf.data.size()), capacity);

	EXPECT_EQ(buf.read_pos, 0);

	for (int i = 0; i < capacity; ++i) {
		EXPECT_EQ(buf.data[static_cast<std::size_t>(i)], 0);
	}
}

// TEST abnormal condition.
TEST(RingBufferTest, MakeRingBufferZeroCapacity) {
	auto buf = MakeRingBuffer<float>(0);

	EXPECT_EQ(buf.capacity, 0);
	EXPECT_EQ(buf.data.size(), 0u);
	EXPECT_EQ(buf.read_pos, 0);
}

// TEST too much capacity.
TEST(RingBufferTest, MakeRingBufferLargeCapacity) {
	constexpr int capacity = 32768;
	auto buf = MakeRingBuffer<short>(capacity);

	EXPECT_EQ(buf.capacity, capacity);
	EXPECT_EQ(buf.data.size(), static_cast<std::size_t>(capacity));
}