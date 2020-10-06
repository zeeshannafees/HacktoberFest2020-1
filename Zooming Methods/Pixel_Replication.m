clear all;
close all;
clc;
mat_img = randi([0,255] ,10);
f=2;
i=1;
for num=1:10
    result(:,i)=mat_img(:,num);
        for t=1:f
            result(:,i+f-1)=result(:,i);
        end
    i=i+f;
end
[r,c]=size(result);
i=1;

for num=1:r
    final_result(i,:)=result(num,:);
    for t=1:f
        final_result(i+t-1,:)=final_result(i,:);
    end
    i=i+f;
end
subplot(2,2,1), imshow(uint8(mat_img));
subplot(2,2,2), imshow(uint8(final_result));
mat_img1=randi(256,10,10,3);
f=2;
i=1;
for num=1:10
    for k=1:3
    result1(:,i,k)=mat_img1(:,num,k);
    end
        for t=1:f
            for k=1:3
            result1(:,i+f-1,k)=result1(:,i,k);
            end
        end
    i=i+f;
end
[r,c]=size(result1);
i=1;
for num=1:r
    for k=1:3
    final_result1(i,:,k)=result1(num,:,k);
    end

    for t=1:f
        for k=1:3
        final_result1(i+t-1,:,k)=final_result1(i,:,k);
        end
    end
    i=i+f;
end
subplot(2,2,3), imshow(uint8(mat_img1));
subplot(2,2,4), imshow(uint8(final_result1));