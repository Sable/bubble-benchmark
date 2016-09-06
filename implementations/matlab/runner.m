function runner(size)

A=(rand(1,size));
A=floor(100*A);

tic();
y=bubble(A);
elapsedTime = toc();

disp('{')
disp('"options":')
disp(size)
disp(', "time":')
disp(elapsedTime)
disp(', "output":')
disp(checksum(y))
disp('}')

end

function [output] = checksum(A) 
    sum1 = 0;
    sum2 = 0;
    
    for i=1:length(A)
        sum1 = mod(sum1 + A(i), 255);
        sum2 = mod(sum2 + sum1, 255);
    end

    output = int32(sum2 * 256 + sum1); 
end
