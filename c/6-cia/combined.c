/*
 * =============================================================
 *         K W I S H   S W I S S   B A N K
 *         Integrated Banking System — v1.0
 * =============================================================
 *
 *  Made by:
 *    2640227   Krish Gupta
 *    2640218   Hardik Tiwari
 *    2640222   Jangham Raja Shivaji
 *    2640219   Ihsan Karayath
 *
 * =============================================================
 *  Modules
 *  -------
 *  [1] Account Creation
 *  [2] Menu-driven Banking Application
 *  [3] Deposit & Withdrawal Operations
 *  [4] Interest Calculator (Simple & Compound)
 *  [+] Transaction History  (bonus feature)
 * =============================================================
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_TXN     50
#define MIN_BALANCE 500.0f
#define NAME_LEN    50

typedef struct {
    char  type[20];
    float amount;
    float balance_after;
} Transaction;

Transaction txn_log[MAX_TXN];
int         txn_count = 0;

void log_txn(const char *type, float amount, float balance_after)
{
    if (txn_count < MAX_TXN) {
        strncpy(txn_log[txn_count].type, type, 19);
        txn_log[txn_count].type[19]      = '\0';
        txn_log[txn_count].amount        = amount;
        txn_log[txn_count].balance_after = balance_after;
        txn_count++;
    }
}

void print_banner(void)
{
    printf("\n");
    printf("  +=============================================+\n");
    printf("  |      K W I S H   S W I S S   B A N K       |\n");
    printf("  |       Your Trusted Financial Partner        |\n");
    printf("  +=============================================+\n");
    printf("  |  2640227  Krish Gupta                       |\n");
    printf("  |  2640218  Hardik Tiwari                     |\n");
    printf("  |  2640222  Jangham Raja Shivaji              |\n");
    printf("  |  2640219  Ihsan Karayath                    |\n");
    printf("  +=============================================+\n");
}

void print_line(void)
{
    printf("  ---------------------------------------------\n");
}

void print_section(const char *title)
{
    printf("\n");
    print_line();
    printf("  %s\n", title);
    print_line();
}

/* =============================================================
 *  MODULE 1 — Account Creation
 *  Contribution: Krish Gupta, Hardik Tiwari
 *  Source: main.c (Kwish Swiss Bank account opening)
 * ============================================================= */
void module_create_account(char name[], int *age, char *acc_type,
                            int *acc_no, float *balance, int *created)
{
    print_section("MODULE 1 — ACCOUNT CREATION");

    printf("  Enter account type (S = Savings, C = Current): ");
    scanf(" %c", acc_type);

    switch (*acc_type) {
        case 'S': case 's':
            printf("  Savings account selected.\n");
            break;
        case 'C': case 'c':
            printf("  Current account selected.\n");
            break;
        default:
            printf("  Invalid account type entered.\n");
            return;
    }

    printf("  Enter your name : ");
    scanf("%49s", name);
    printf("  Enter your age  : ");
    scanf("%d", age);

    if (*age < 18) {
        printf("  You must be at least 18 years old to open an account.\n");
        return;
    }

    *acc_no  = name[0] * 100000 + *age;
    *created = 1;

    printf("  Enter initial deposit amount: ");
    scanf("%f", balance);

    if (*balance > 0)
        log_txn("Opening Deposit", *balance, *balance);

    printf("\n");
    printf("  Account opening successful for %s, age %d.\n", name, *age);
    printf("  Account Number : %d\n",   *acc_no);
    printf("  Account Type   : %s\n",
           (*acc_type == 'S' || *acc_type == 's') ? "Savings" : "Current");
    printf("  Opening Balance: %.2f\n", *balance);
    printf("  Thank you for choosing Kwish Swiss Bank!\n");
    print_line();
}

/* =============================================================
 *  MODULE 2 & 3 — Menu-driven Banking Application
 *                  Deposit & Withdrawal Operations
 *  Contribution: Jangham Raja Shivaji, Ihsan Karayath
 *  Source: deposit_money_and_withdrawl.txt
 * ============================================================= */
void module_banking_operations(float *balance, int created)
{
    if (!created) {
        printf("\n  Please create an account first (Main Menu > Option 1).\n");
        return;
    }

    float amount;
    int   choice;

    do {
        print_section("MODULE 2 & 3 — BANKING OPERATIONS");
        printf("  1. Deposit\n");
        printf("  2. Withdraw\n");
        printf("  3. Check Balance\n");
        printf("  4. Back to Main Menu\n");
        print_line();
        printf("  Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("  Enter amount to deposit: ");
                scanf("%f", &amount);
                if (amount <= 0) {
                    printf("  Invalid amount. Please enter a positive value.\n");
                    break;
                }
                *balance += amount;
                log_txn("Deposit", amount, *balance);
                printf("  Amount Deposited Successfully!\n");
                printf("  Current Balance = %.2f\n", *balance);
                break;

            case 2:
                printf("  Enter amount to withdraw: ");
                scanf("%f", &amount);
                if (amount <= 0) {
                    printf("  Invalid amount. Please enter a positive value.\n");
                    break;
                }
                if (amount <= *balance) {
                    *balance -= amount;
                    log_txn("Withdrawal", amount, *balance);
                    printf("  Amount Withdrawn Successfully!\n");
                    printf("  Current Balance = %.2f\n", *balance);
                    if (*balance < MIN_BALANCE)
                        printf("  ** Warning: Balance is below minimum (%.2f)! **\n",
                               MIN_BALANCE);
                } else {
                    printf("  Insufficient Balance!\n");
                }
                break;

            case 3:
                printf("  Current Balance = %.2f\n", *balance);
                break;

            case 4:
                printf("  Returning to Main Menu...\n");
                break;

            default:
                printf("  Invalid Choice!\n");
        }

    } while (choice != 4);
}

/* =============================================================
 *  MODULE 4 — Interest Calculator (Simple & Compound)
 *  Contribution: All members
 *  Source: New module — integrates with account balance
 * ============================================================= */
void module_interest_calculator(float balance, char acc_type)
{
    int   choice;
    float principal, rate, time, interest, final_amount;

    print_section("MODULE 4 — INTEREST CALCULATOR");
    printf("  1. Simple Interest\n");
    printf("  2. Compound Interest\n");
    printf("  3. Back to Main Menu\n");
    print_line();
    printf("  Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 3) return;
    if (choice != 1 && choice != 2) {
        printf("  Invalid Choice!\n");
        return;
    }

    if (balance > 0) {
        char use_bal;
        printf("  Use current account balance (%.2f) as principal? (Y/N): ", balance);
        scanf(" %c", &use_bal);
        if (use_bal == 'Y' || use_bal == 'y')
            principal = balance;
        else {
            printf("  Enter Principal Amount: ");
            scanf("%f", &principal);
        }
    } else {
        printf("  Enter Principal Amount: ");
        scanf("%f", &principal);
    }

    printf("  Enter Annual Rate of Interest (%%): ");
    scanf("%f", &rate);
    printf("  Enter Time Period (years)         : ");
    scanf("%f", &time);

    if (choice == 1) {
        interest     = (principal * rate * time) / 100.0f;
        final_amount = principal + interest;
        printf("\n  --- Simple Interest Result ---\n");
    } else {
        final_amount = principal * (float)pow(1.0 + rate / 100.0, time);
        interest     = final_amount - principal;
        printf("\n  --- Compound Interest Result ---\n");
    }

    print_line();
    printf("  Principal     : %.2f\n",   principal);
    printf("  Rate          : %.2f %%\n", rate);
    printf("  Time          : %.2f yrs\n", time);
    printf("  Interest      : %.2f\n",   interest);
    printf("  Total Amount  : %.2f\n",   final_amount);
    print_line();

    if (acc_type == 'S' || acc_type == 's')
        printf("  Tip: Savings accounts typically earn Simple Interest.\n");
    else if (acc_type == 'C' || acc_type == 'c')
        printf("  Tip: Current accounts may attract Compound Interest on overdrafts.\n");
}

/* =============================================================
 *  BONUS — Transaction History
 *  Contribution: All members
 * ============================================================= */
void module_transaction_history(void)
{
    print_section("TRANSACTION HISTORY");

    if (txn_count == 0) {
        printf("  No transactions recorded yet.\n");
        print_line();
        return;
    }

    printf("  %-4s  %-18s  %-12s  %-12s\n",
           "S.No", "Type", "Amount", "Balance After");
    print_line();

    for (int i = 0; i < txn_count; i++) {
        printf("  %-4d  %-18s  %-12.2f  %-12.2f\n",
               i + 1,
               txn_log[i].type,
               txn_log[i].amount,
               txn_log[i].balance_after);
    }
    print_line();
    printf("  Total Transactions: %d\n", txn_count);
    print_line();
}

/* =============================================================
 *  MAIN — Master Menu
 * ============================================================= */
int main(void)
{
    print_banner();

    char  name[NAME_LEN] = "";
    int   age            = 0;
    char  acc_type       = '\0';
    int   acc_no         = 0;
    float balance        = 0.0f;
    int   created        = 0;

    int choice;

    do {
        printf("\n");
        printf("  +=============================================+\n");
        printf("  |                MAIN MENU                    |\n");
        printf("  +=============================================+\n");
        printf("  1. Create Account\n");
        printf("  2. Banking Operations   (Deposit / Withdraw)\n");
        printf("  3. Interest Calculator  (Simple & Compound)\n");
        printf("  4. View Transaction History\n");
        printf("  5. Exit\n");
        print_line();
        printf("  Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                module_create_account(name, &age, &acc_type,
                                      &acc_no, &balance, &created);
                break;

            case 2:
                module_banking_operations(&balance, created);
                break;

            case 3:
                module_interest_calculator(balance, acc_type);
                break;

            case 4:
                module_transaction_history();
                break;

            case 5:
                print_banner();
                printf("\n  Thank You for banking with Kwish Swiss Bank!\n");
                if (created) {
                    print_line();
                    printf("  Account Holder : %s\n",  name);
                    printf("  Account Number : %d\n",  acc_no);
                    printf("  Account Type   : %s\n",
                           (acc_type == 'S' || acc_type == 's')
                           ? "Savings" : "Current");
                    printf("  Final Balance  : %.2f\n", balance);
                    printf("  Transactions   : %d\n",   txn_count);
                }
                printf("  Goodbye!\n");
                print_line();
                break;

            default:
                printf("  Invalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}

/*
 * =============================================================
 *  References
 *  ----------
 *  [1] Online C Compiler. GCC.
 *      https://www.onlinegdb.com/
 *
 *  [2] What is Kiosk Banking. Indusland Bank.
 *      https://www.indusind.bank.in/iblogs/savings-account/what-is-kiosk-banking/
 *
 *  [3] Kiosk Banking: A way forward. LIPI.
 *      https://lipi.in/insights/kiosk-banking/
 * =============================================================
 */
