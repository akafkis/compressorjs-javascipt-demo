```cpp
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Compressor.h"
#include "utilities.h"

using namespace Compressor;
using namespace testing;

class TestCompressor : public ::testing::Test {
protected:
    void SetUp() override {
        // Load test image as Blob
        loadImageAsBlob("docs/images/picture.jpg", [this](Blob* blob) {
            testImage = blob;
        });
    }

    void TearDown() override {
        delete testImage;
    }

    Blob* testImage = nullptr;
};

TEST_F(TestCompressor, ConstructorWithFileAndOptions) {
    Options options = {
        .strict = false,
        .checkOrientation = false,
        .retainExif = true,
        .maxWidth = 1024,
        .maxHeight = 768,
        .minWidth = 100,
        .minHeight = 100,
        .width = 800,
        .height = 600,
        .resize = "cover",
        .quality = 0.9,
        .mimeType = "image/jpeg",
        .convertTypes = "image/png",
        .convertSize = 1000000,
        .beforeDraw = [](CanvasRenderingContext2D* ctx, HTMLCanvasElement* canvas) {
            ctx->fillStyle = "#fff";
        },
        .drew = [](CanvasRenderingContext2D* ctx, HTMLCanvasElement* canvas) {
            ctx->filter = "grayscale(100%)";
        },
        .success = [](Blob* file) {
            // Handle success
        },
        .error = [](Error* err) {
            // Handle error
        }
    };

    Compressor compressor(testImage, &options);
    ASSERT_EQ(compressor.options.strict, false);
    ASSERT_EQ(compressor.options.checkOrientation, false);
    ASSERT_EQ(compressor.options.retainExif, true);
    ASSERT_EQ(compressor.options.maxWidth, 1024);
    ASSERT_EQ(compressor.options.maxHeight, 768);
    ASSERT_EQ(compressor.options.minWidth, 100);
    ASSERT_EQ(compressor.options.minHeight, 100);
    ASSERT_EQ(compressor.options.width, 800);
    ASSERT_EQ(compressor.options.height, 600);
    ASSERT_EQ(compressor.options.resize, "cover");
    ASSERT_EQ(compressor.options.quality, 0.9);
    ASSERT_EQ(compressor.options.mimeType, "image/jpeg");
    ASSERT_EQ(compressor.options.convertTypes, "image/png");
    ASSERT_EQ(compressor.options.convertSize, 1000000);
    ASSERT_NE(compressor.options.beforeDraw, nullptr);
    ASSERT_NE(compressor.options.drew, nullptr);
    ASSERT_NE(compressor.options.success, nullptr);
    ASSERT_NE(compressor.options.error, nullptr);
}

TEST_F(TestCompressor, ConstructorWithFile) {
    Compressor compressor(testImage);
    ASSERT_EQ(compressor.options.strict, true);
    ASSERT_EQ(compressor.options.checkOrientation, true);
    ASSERT_EQ(compressor.options.retainExif, false);
    ASSERT_EQ(compressor.options.maxWidth, INFINITY);
    ASSERT_EQ(compressor.options.maxHeight, INFINITY);
    ASSERT_EQ(compressor.options.minWidth, 0);
    ASSERT_EQ(compressor.options.minHeight, 0);
    ASSERT_EQ(compressor.options.width, undefined);
    ASSERT_EQ(compressor.options.height, undefined);
    ASSERT_EQ(compressor.options.resize, "none");
    ASSERT_EQ(compressor.options.quality, 0.8);
    ASSERT_EQ(compressor.options.mimeType, "auto");
    ASSERT_EQ(compressor.options.convertTypes, "image/png");
    ASSERT_EQ(compressor.options.convertSize, 5000000);
    ASSERT_EQ(compressor.options.beforeDraw, nullptr);
    ASSERT_EQ(compressor.options.drew, nullptr);
    ASSERT_EQ(compressor.options.success, nullptr);
    ASSERT_EQ(compressor.options.error, nullptr);
}

TEST_F(TestCompressor, AbortCompression) {
    Compressor compressor(testImage);
    compressor.abort();
    // TODO: Add assertions to verify abort functionality
}

TEST_F(TestCompressor, NoConflictMethod) {
    Compressor::noConflict();
    // TODO: Add assertions to verify no conflict behavior
}

TEST_F(TestCompressor, SetDefaultsMethod) {
    Options newDefaults = {
        .strict = false,
        .checkOrientation = false,
        .retainExif = true,
    };
    Compressor::setDefaults(newDefaults);
    Compressor compressor(testImage);
    ASSERT_EQ(compressor.options.strict, false);
    ASSERT_EQ(compressor.options.checkOrientation, false);
    ASSERT_EQ(compressor.options.retainExif, true);
}

TEST_F(TestCompressor, ResizeOptionBehavior) {
    Options options = {
        .width = 800,
        .height = 600,
        .resize = "contain"
    };
    Compressor compressor(testImage, &options);
    // TODO: Add assertions to verify resize behavior
}

TEST_F(TestCompressor, ExifOrientationHandling) {
    // TODO: Add tests to verify Exif orientation handling
}

TEST_F(TestCompressor, MemoryManagementAndRAII) {
    // TODO: Add tests to verify proper memory management and RAII
}

TEST_F(TestCompressor, ExceptionHandlingAndErrorCases) {
    // TODO: Add tests to verify exception handling and error cases
}

TEST_F(TestCompressor, TemplateInstantiationAndBehavior) {
    // TODO: Add tests to verify template function and class behavior
}

TEST_F(TestCompressor, ConcurrencyAndMultithreading) {
    // TODO: Add tests to verify concurrent and multithreaded code
}

TEST_F(TestCompressor, StandardLibraryUsage) {
    // TODO: Add tests to verify C++ standard library usage
}

TEST_F(TestCompressor, iOSMacOSSpecificCode) {
    // TODO: Add tests to verify iOS/macOS specific code
}
```