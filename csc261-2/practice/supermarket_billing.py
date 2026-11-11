customer_name = input("Enter customer name: ")

item1_name = input("Enter name of item 1: ")
item1_price = float(input("Enter price of item 1: "))
item1_qty = int(input("Enter quantity of item 1: "))

item2_name = input("Enter name of item 2: ")
item2_price = float(input("Enter price of item 2: "))
item2_qty = int(input("Enter quantity of item 2: "))

item3_name = input("Enter name of item 3: ")
item3_price = float(input("Enter price of item 3: "))
item3_qty = int(input("Enter quantity of item 3: "))

amount1 = item1_price * item1_qty
amount2 = item2_price * item2_qty
amount3 = item3_price * item3_qty

total = amount1 + amount2 + amount3
discount = total * 5 / 100
final_amount = total - discount

print()
print("===== SUPERMARKET BILL =====")
print("Customer Name :", customer_name)
print("------------------------------")
print("Item 1 :", item1_name)
print("Price  :", item1_price)
print("Qty    :", item1_qty)
print("Amount :", amount1)
print("------------------------------")
print("Item 2 :", item2_name)
print("Price  :", item2_price)
print("Qty    :", item2_qty)
print("Amount :", amount2)
print("------------------------------")
print("Item 3 :", item3_name)
print("Price  :", item3_price)
print("Qty    :", item3_qty)
print("Amount :", amount3)
print("------------------------------")
print("Total         :", total)
print("Discount (5%) :", discount)
print("Final Amount  :", final_amount)
print("==============================")
