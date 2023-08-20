def Gross_Salary(basic,grade):
  hra=basic*0.2
  da=basic*0.5
  allow
  if(grade=='A'):
    allow=1700
  elif(grade=='B'):
    allow=1500
  elif(grade=='C'):
    allow=1300
  pf=basic*0.11
  Salary=basic+hra+da+allow-pf
  return Salary
  
