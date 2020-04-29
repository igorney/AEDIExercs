compra = float(input("Digite o valor da sua compra: "))
parcelas = int(input("Digite as parcelas: "))
if parcelas >= 2  and parcelas < 4: #condição para parcela
    compra = compra + compra * 0.02 #acrescentando juros 
    parcelas = compra/parcelas #calculando parcela
elif parcelas >= 4 and parcelas < 6:
    compra = compra + compra * 0.07 #acrescentando juros 
    parcelas = compra/parcelas #calculando parcela
elif parcelas >= 6 and parcelas < 8:
    compra = compra + compra * 0.09 #acrescentando juros 
    parcelas = compra/parcelas #calculando parcela
elif parcelas >= 8:
    compra = compra + compra * 0.12 #acrescentando juros 
    parcelas = compra/parcelas #calculando parcela
else:
    print("Valor total da sua mãe! : ", parcelas)

print("Valor total da parcela: ", parcelas)