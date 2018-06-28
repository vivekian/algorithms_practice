#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

/*  Each loan consists of one line containing the duration in
months of the loan, the down payment, the amount of the loan, and the number of depreciation records
that follow. All values are nonnegative, with loans being at most 100 months long and car values at most
$75,000. */ 

struct drec 
{
    uint32_t month; 
    float dep;
};

struct loan 
{
   int num_months; 
   float downpayment;
   float loan_amount;
   uint32_t num_depr_records;
   vector<drec> drecs;
};

void process_loan(const loan& l) 
{
   float curr_value = l.loan_amount + l.downpayment; 
   float loan_remaining = l.loan_amount;
   float monthly_payment = l.loan_amount / l.num_months;

   for (int rec=0; rec<l.drecs.size(); ++rec) 
   {
      int smonth = l.drecs[rec].month; 
      int emonth = (rec == l.drecs.size()-1) ? l.num_months: l.drecs[rec+1].month; 

      for (int m=smonth; m<emonth; ++m) 
      {
            curr_value -= (curr_value * l.drecs[rec].dep); 
            loan_remaining -= monthly_payment;

//            cout << m << " " << loan_remaining << " " << curr_value << endl;

            if (loan_remaining < curr_value) 
            {
               cout << m+1 << " month" << ((m+1==1)?"":"s") << endl; 
               return; 
            }
      }
   }
}

int main()
{
    vector<loan> loans;

    do { 
        loan l;
        scanf("%d %f %f %u", &l.num_months, &l.downpayment, &l.loan_amount, &l.num_depr_records);
        
        if (l.num_months < 0) 
        { 
            break;
        }

        for (int i=0; i<l.num_depr_records; ++i) 
        {
             drec rec; 
             scanf("%u %f", &rec.month, &rec.dep);
             l.drecs.push_back(move(rec));
        }

        loans.push_back(std::move(l)); 
    }while (1);

    for (const auto& l: loans)
    {
       process_loan(l);  
    }

    return 0;  
}
