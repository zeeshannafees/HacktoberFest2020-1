mat_img = randi([0,255] ,10);
mat_img1=randi(256,10,10,3);

k=3;
[r, c]=size(mat_img);
for a=1:r
    for b=1:c-1
            temp=k;
            steps=abs(floor((mat_img(a,b+1)-mat_img(a,b))/k));
            num=0;
            while temp>=1
                temp=temp-1;
                j(a,b*k-num)=mat_img(a,b)+steps*temp;
                num=num+1;
            end
    end
end
j(:,b*k+1) = mat_img(:,b);
[r2 , c2]=size(j);
for a=1:r2-1
    for b=1:c2
            temp=k;
            steps=abs(floor((j(a+1,b)-j(a,b))/k));
            num=0;
            while temp>=1
                temp=temp-1;
                u(a*k-num,b)=j(a,b)+steps*temp;
                num=num+1;
            end 
    end
end
u(a*k+1,:) = j(a,:);
subplot(2,2,1), imshow(uint8(mat_img));
subplot(2,2,2), imshow(uint8(u));

k=3;
[r, c, p]=size(mat_img1);
for a=1:r
    for b=1:c-1
            temp=k;
            steps=abs(floor((mat_img1(a,b+1,1)-mat_img1(a,b,1))/k));
            steps1=abs(floor((mat_img1(a,b+1,2)-mat_img1(a,b,2))/k));
            steps2=abs(floor((mat_img1(a,b+1,3)-mat_img1(a,b,3))/k));
            num=0;
            while temp>=1
                temp=temp-1;
                j1(a,b*k-num,1)=mat_img1(a,b,1)+steps*temp;
                j1(a,b*k-num,2)=mat_img1(a,b,2)+steps1*temp;
                j1(a,b*k-num,3)=mat_img1(a,b,3)+steps2*temp;
                num=num+1;
            end
    end
end
j1(:,b*k+1,:) = mat_img1(:,b,:) ;
[r2 , c2 , p]=size(j);
k=3;
for a=1:r2-1
    for b=1:c2
            temp=k;
            steps=abs(floor((j1(a+1,b,1)-j1(a,b,1))/k));
            steps1=abs(floor((j1(a+1,b,2)-j1(a,b,2))/k));
            steps2=abs(floor((j1(a+1,b,3)-j1(a,b,3))/k));
            num=0;
            while temp>=1
                temp=temp-1;
                u1(a*k-num,b,1)=j1(a,b,1)+steps*temp;
                u1(a*k-num,b,2)=j1(a,b,2)+steps1*temp;
                u1(a*k-num,b,3)=j1(a,b,3)+steps2*temp;
                num=num+1;
            end 
    end
end
u1(a*k+1,:,:) = j1(a,:,:);
subplot(2,2,3), imshow(uint8(mat_img1));
subplot(2,2,4), imshow(cast(u1,'uint8'));