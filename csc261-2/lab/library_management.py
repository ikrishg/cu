member_name = input("Enter member name: ")
is_student = input("Is student member? (yes/no): ") == "yes"

book1_name = input("Enter name of book 1: ")
book1_days = int(input("Enter overdue days for book 1: "))
book1_rate = float(input("Enter fine rate for book 1: "))

book2_name = input("Enter name of book 2: ")
book2_days = int(input("Enter overdue days for book 2: "))
book2_rate = float(input("Enter fine rate for book 2: "))

book3_name = input("Enter name of book 3: ")
book3_days = int(input("Enter overdue days for book 3: "))
book3_rate = float(input("Enter fine rate for book 3: "))

fine1 = book1_days * book1_rate
fine2 = book2_days * book2_rate
fine3 = book3_days * book3_rate
total_fine = fine1 + fine2 + fine3

discount = 0.0
if is_student and total_fine >= 20:
  discount = total_fine * 10 / 100
final_fine = total_fine - discount

must_pay = final_fine > 0
can_issue_more = final_fine == 0 or (is_student and final_fine < 50)

print()
print("===== LIBRARY FINE REPORT =====")
print("Member Name :", member_name)
print("Student     :", is_student)
print("------------------------------")
print("Book 1 :", book1_name)
print("Days   :", book1_days)
print("Rate   :", book1_rate)
print("Fine   :", fine1)
print("------------------------------")
print("Book 2 :", book2_name)
print("Days   :", book2_days)
print("Rate   :", book2_rate)
print("Fine   :", fine2)
print("------------------------------")
print("Book 3 :", book3_name)
print("Days   :", book3_days)
print("Rate   :", book3_rate)
print("Fine   :", fine3)
print("------------------------------")
print("Total Fine      :", total_fine)
print("Discount (10%)  :", discount)
print("Final Fine      :", final_fine)
print("Must Pay        :", must_pay)
print("Can Issue More  :", can_issue_more)
print("==============================")
