from UnidadeDeControle import *

uc = UnidadeDeControle()

op=1
while (op != 0):
    print   "\n\n##CALCULADORA##" \
            "\n1 - Executar por instrucoes" \
            "\n2 - Visualizar instrucoes" \
            "\n3 - Executar utilizando expressoes" \
            "\n0 - SAIR"
    op = int(input("Escolha uma opcao: "))

    if (op == 1):
        continuar = True
        while(continuar):
            uc.cpu.setM(float(input("Informe o valor de M: ")))
            uc.cpu.setIR(raw_input("Instrucao: ").upper())
            uc.cpu.cicloDeInstrucao()
            print "Resultado: ", uc.cpu.AC
            continuar=bool(input("Deseja inserir outro valor: 0-NAO | 1-SIM"))
        uc.cpu.reset()


    elif (op == 2):
        print "\tINSTRUCAO\tOPCODE\t\tDESCRICAO"
        for i in uc.cpu.opcode.keys():
            print "\t" + i.ljust(12,' ') + str(uc.cpu.opcode[i][0]).ljust(12,' ') + uc.cpu.opcode[i][1]


    elif (op == 3):
        uc.mp.addInstrucoes(raw_input("Informe as instrucoes (separadas por virgula): ").upper().split(","))
        uc.mp.addDados(raw_input("Informe os valores (numeros, separados por virgula): ").split(","))
        uc.executar()
        print "Resultado: ", uc.cpu.AC
        uc.cpu.reset()