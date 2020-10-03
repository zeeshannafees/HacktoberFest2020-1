#this program will help sellar to get final price after gst is added.
def gst_electronics(amount):
    # as of now 2020 gst percent for electronic items is 18%
    gst_tax = 0.18*float(amount);
    total_bill = float(amount) + gst_tax;
    print("gst tax ="+ str(gst_tax))
    print("total bill ="+ str(total_bill))


def gst_automobiles(amount):
    # as of now 2020 gst percent for electronic items is 28%
    gst_tax = 0.28*float(amount);
    total_bill = float(amount) + gst_tax;
    print("gst tax ="+str(gst_tax))
    print("total bill ="+str(total_bill))


while(1):
    option = int(input("please enter [1] for electronics goods , [2] for automobile parts, [3] to exit : "))
    if option == 1:
        amount = int(input("please enter orignal amount for your electronic goods : "))
        gst_electronics(amount)
    if option == 2:
        amount = int(input("please enter orignal amount for your automobile parts : "))
        gst_automobiles(amount)
    if option == 3:
        break