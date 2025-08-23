#include "CppUTest/TestHarness.h"

// Must be the last include!
#include "CppUTest/MemoryLeakDetectorMallocMacros.h"

//production code includes
#include "Buffer.hpp"

TEST_GROUP(BufferTest)
{
    App::Buffer* buffer;

    void setup()
    {
        buffer = new App::Buffer();
    }

    void teardown()
    {
        delete buffer; // destructor leaks memory
    }
};

TEST(BufferTest, DetectsLeakWhenNotReleased)
{
    buffer->allocate(256);   // allocated but not freed
    CHECK_TRUE(buffer->getBuffer() != nullptr);
    // Leak will be reported
}

TEST(BufferTest, NoLeakWhenReleased)
{
    buffer->allocate(256);
    buffer->release();   // freed
    CHECK_TRUE(buffer->getBuffer() == nullptr);
    // No leak
}

TEST(BufferTest, MultipleAllocationsWithoutRelease)
{
    buffer->allocate(128);
    buffer->allocate(256);  // overwrites pointer, leaks first block
    CHECK_TRUE(buffer->getBuffer() != nullptr);
}
