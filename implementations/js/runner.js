var twister = require('./twister/ostrich-twister-prng.js');

function runner(size) {
    if (typeof performance === 'undefined') {
        performance = Date;            
    }

    var a = new Int32Array(size);
    for (var i = 0; i < a.length; ++i) {
        a[i] = Math.floor(100*twister.rand());
    }

    var start = performance.now();
    y=bubble(a);
    var elapsedTime = performance.now() - start;
    
    console.log(JSON.stringify({
        options: size,
        time: elapsedTime / 1000,
        output: checksum(a)
    }))
}

function checksum(a) {
    // Use the Fletcher sum to detect changes
    // in the position of array elements
    var sum1 = 0;
    var sum2 = 0;
    for (var i = 0; i < a.length; ++i) {
        sum1 = (sum1 + a[i]) % 255;
        sum2 = (sum2 + sum1) % 255;
    }
    return (sum2 << 8) | sum1;
}
