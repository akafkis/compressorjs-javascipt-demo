```java
package com.example.Compressor;

import com.example.Compressor.Compressor;
import com.example.Compressor.Options;
import com.example.Compressor.Error;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.CsvSource;
import org.mockito.Mock;
import org.mockito.MockitoAnnotations;

import java.util.function.Consumer;

import static org.junit.jupiter.api.Assertions.*;
import static org.mockito.Mockito.*;

class CompressorTest {
    @Mock
    private Blob testImage;

    @Mock
    private Consumer<Blob> successCallback;

    @Mock
    private Consumer<Error> errorCallback;

    @BeforeEach
    void setUp() {
        MockitoAnnotations.openMocks(this);
    }

    @Test
    void constructorWithFileAndOptions() {
        Options options = new Options();
        options.strict = false;
        options.checkOrientation = false;
        options.retainExif = true;
        options.maxWidth = 1024;
        options.maxHeight = 768;
        options.minWidth = 100;
        options.minHeight = 100;
        options.width = 800;
        options.height = 600;
        options.resize = "cover";
        options.quality = 0.9;
        options.mimeType = "image/jpeg";
        options.convertTypes = "image/png";
        options.convertSize = 1000000;
        options.beforeDraw = (ctx, canvas) -> ctx.fillStyle = "#fff";
        options.drew = (ctx, canvas) -> ctx.filter = "grayscale(100%)";
        options.success = successCallback;
        options.error = errorCallback;

        Compressor compressor = new Compressor(testImage, options);

        assertEquals(false, compressor.options.strict);
        assertEquals(false, compressor.options.checkOrientation);
        assertEquals(true, compressor.options.retainExif);
        assertEquals(1024, compressor.options.maxWidth);
        assertEquals(768, compressor.options.maxHeight);
        assertEquals(100, compressor.options.minWidth);
        assertEquals(100, compressor.options.minHeight);
        assertEquals(800, compressor.options.width);
        assertEquals(600, compressor.options.height);
        assertEquals("cover", compressor.options.resize);
        assertEquals(0.9, compressor.options.quality);
        assertEquals("image/jpeg", compressor.options.mimeType);
        assertEquals("image/png", compressor.options.convertTypes);
        assertEquals(1000000, compressor.options.convertSize);
        assertNotNull(compressor.options.beforeDraw);
        assertNotNull(compressor.options.drew);
        assertSame(successCallback, compressor.options.success);
        assertSame(errorCallback, compressor.options.error);
    }

    @Test
    void constructorWithFile() {
        Compressor compressor = new Compressor(testImage);

        assertEquals(true, compressor.options.strict);
        assertEquals(true, compressor.options.checkOrientation);
        assertEquals(false, compressor.options.retainExif);
        assertEquals(Double.POSITIVE_INFINITY, compressor.options.maxWidth);
        assertEquals(Double.POSITIVE_INFINITY, compressor.options.maxHeight);
        assertEquals(0, compressor.options.minWidth);
        assertEquals(0, compressor.options.minHeight);
        assertNull(compressor.options.width);
        assertNull(compressor.options.height);
        assertEquals("none", compressor.options.resize);
        assertEquals(0.8, compressor.options.quality);
        assertEquals("auto", compressor.options.mimeType);
        assertEquals("image/png", compressor.options.convertTypes);
        assertEquals(5000000, compressor.options.convertSize);
        assertNull(compressor.options.beforeDraw);
        assertNull(compressor.options.drew);
        assertNull(compressor.options.success);
        assertNull(compressor.options.error);
    }

    @Test
    void abortCompression() {
        Compressor compressor = new Compressor(testImage);
        compressor.abort();
        // TODO: Add assertions to verify abort functionality
    }

    @Test
    void noConflictMethod() {
        Compressor.noConflict();
        // TODO: Add assertions to verify no conflict behavior
    }

    @Test
    void setDefaultsMethod() {
        Options newDefaults = new Options();
        newDefaults.strict = false;
        newDefaults.checkOrientation = false;
        newDefaults.retainExif = true;

        Compressor.setDefaults(newDefaults);

        Compressor compressor = new Compressor(testImage);
        assertEquals(false, compressor.options.strict);
        assertEquals(false, compressor.options.checkOrientation);
        assertEquals(true, compressor.options.retainExif);
    }

    @ParameterizedTest
    @CsvSource({"800, 600, contain", "400, 300, cover"})
    void resizeOptionBehavior(int width, int height, String resize) {
        Options options = new Options();
        options.width = width;
        options.height = height;
        options.resize = resize;

        Compressor compressor = new Compressor(testImage, options);
        // TODO: Add assertions to verify resize behavior
    }

    // TODO: Add tests to verify Exif orientation handling
    // TODO: Add tests to verify proper memory management and RAII
    // TODO: Add tests to verify exception handling and error cases
    // TODO: Add tests to verify template function and class behavior
    // TODO: Add tests to verify concurrent and multithreaded code
    // TODO: Add tests to verify C++ standard library usage
    // TODO: Add tests to verify iOS/macOS specific code
}
```