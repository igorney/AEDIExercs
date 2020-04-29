h = float(input("Digite sua altura: "))
sexo = str(input("Digite seu sexo, Masculino ou Feminino: "))
if sexo == "masculino" or sexo == "Masculino":
    pesoideal = 22.0 * h ** 2
elif sexo == "feminino" or sexo == "Feminino" :
    pesoideal = 20.8 * h ** 2

print("Seu peso ideal é: ", pesoideal)