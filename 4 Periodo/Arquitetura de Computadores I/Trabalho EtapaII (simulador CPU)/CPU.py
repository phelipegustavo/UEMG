class CPU(object):
    opcode = {
        #------INSTRUCOES DE TRANSFERENCIA------
        #"SET"      :[      00,      "Define valor de M"],
        #"LOAD"     :[      01,      "Transfere o valor de MQ para AC"],
        "LOAD"     :[      10,      "Transfere o valor de M para AC"],
        #------INSTRUCOES ARITMETICA------
        #"INSERT"   :[    1001,      "Insere M em"],
        "ADD"      :[      11,      "Soma M a AC e coloca o resultado em AC"],
        "SUB"      :[     101,      "Subtrai M de AC e coloca o resultado em AC"],
        "MUL"      :[     111,      "Multiplica M por MQ e coloca os bits mais significativos do resultado em AC e os menos em MQ"],
        "DIV"      :[    1000,      "Divide AC por M e coloca o quociente em MQ e o resto em AC"],
    }

    PC  = 0  #Contador de Programas
    IR  = 0  #Registrador de Instrucao, Opcode
    MAR = 0  #Registrador de endereco de memoria (Dados de entrada e/ou saida)
    MBR = 0  #Registrador de buffer de memoria (Dados de Entrada)
    IBR = 0  #Proxima instrucao a ser executada
    AC  = 0  #Operandos
    MQ  = 0  #Resultados ALU
    M   = 0

    def __init__(self):
        pass

    def setM(self, M):      self.M  = M
    def setIR(self, IR):    self.IR = IR
    def loadM(self):        self.AC =   self.M
    def addMX(self):        self.AC +=  self.M
    def subMX(self):        self.AC -=  self.M
    def multMX(self):       self.AC *= self.M
    def divMX(self):        self.AC /= self.M

    def imprimirCPU(self):
        print "\n\n------CPU------"
        print "PC : ", self.PC
        print "IR : ", self.IR
        print "AC : ", self.AC
        print "MAR: ", self.MAR
        print "MBR: ", self.MBR
        print "---------------\n\n"

    def cicloDeInstrucao(self):
        # Busca
        if self.IR in self.opcode.keys() or self.opcode.values()[0]:
            self.MBR = hex(id(self.M))
            # Executa
            if self.IR == "LOAD" or self.IR == '10': self.loadM()
            elif self.IR == "ADD" or self.IR == '11': self.addMX()
            elif self.IR == "SUB"or self.IR == '101': self.subMX()
            elif self.IR == "MUL" or self.IR == '111': self.multMX()
            elif self.IR == "DIV" or self.IR == '1000': self.divMX()
            self.PC += 1
            self.MAR = hex(id(self.AC))
            self.imprimirCPU()

    def reset(self):
        self.PC     = 0
        self.IR     = 0
        self.MAR    = 0
        self.MBR    = 0
        self.IBR    = 0
        self.AC     = 0
        self.MQ     = 0
        self.M      = 0