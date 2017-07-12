class MemoriaPrincipal(object):
    instrucoes = []
    dados = []

    def __init__(self):
        pass

    def addInstrucao(self, IR):
        self.instrucoes.append(IR)

    def addDado(self, D):
        self.dados.append(D)

    def addInstrucoes(self, ins):
        self.instrucoes = ins

    def addDados(self, dados):
        self.dados = dados

    def endDado(self, i):
        print "Dado, Endereco:  ", self.dados[i], hex(id(self.dados[i]))