# modify this or make a better one
Original_price = input('Enter the original price of the item:')#get input from user
Net_price = input('Enter the net price of the item:')#get input  from user
GST_amount = Net_price - Original_price

GST_percent = ((GST_amount * 100) / Original_price)
print("GST = ",end='') 
#add line to print GST_percent
print(GST_percent, end='')
print("%")
