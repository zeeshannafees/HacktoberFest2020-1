mat_img = randi([0,255] ,10);
mat_img1=randi(256,10,10,3);
[r,c]=size(mat_img);
for a=1:r
    for b=1:c-1
            j(a,2*b-1)=mat_img(a,b);
            j(a,2*b)=round((mat_img(a,b) + mat_img(a,b+1))/2);
    end    
end
j(:,2*b+1) = mat_img(:,b+1);
for a=1:r-1
    for b=1:c*2-1
        k(2*a-1,b)=j(a,b);
        k(2*a,b)=round((j(a,b) + j(a+1,b))/2);
     end   
end
k(2*a+1,:) = j(a+1,:);
subplot(2,2,1), imshow(uint8(mat_img));
subplot(2,2,2), imshow(uint8(k));
[r,c,p]=size(mat_img1);
for a=1:r
    for b=1:c-1
        for w=1:3
            j1(a,2*b-1,w)=mat_img1(a,b,w);
            j1(a,2*b,w)=round((mat_img1(a,b,w) + mat_img1(a,b+1,w))/2);
        end
    end    
end
j1(:,2*b+1,:) = mat_img1(:,b+1,:);
for a=1:r-1
    for b=1:c*2-1
        for w = 1:3
        k2(2*a-1,b,w)=j1(a,b,w);
        k2(2*a,b,w)=round((j1(a,b,w) + j1(a+1,b,w))/2);
        end
     end   
end
k2(2*a+1,:,:) = j1(a+1,:,:);
subplot(2,2,3), imshow(uint8(mat_img1));
subplot(2,2,4), imshow(uint8(k2));