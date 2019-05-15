

USAGE:

  Neuronal NetWork Training:
    Input:
    {"work?","have eny social assistance?","average salary","How many children?","how time invest in study","The person responsible for your current situation is an external factor or it is up to you"}
  -> {"1:y / 0:n", "1:y / 0:n", "1000" , "2" , "8(hours per week)" , "1: me / 0: external"}
    Ex: {1, 0, 20000, 0, 10, 1}

    Output:
    -> Output > 0.5 -> vote CFK
    -> Output < 0.5 -> vote MM
