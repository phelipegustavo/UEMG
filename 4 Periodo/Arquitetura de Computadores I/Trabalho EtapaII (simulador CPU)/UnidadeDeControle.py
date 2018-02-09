from CPU import *
from MemoriaPrincipal import *

class UnidadeDeControle(object):

    cpu = CPU()
    mp = MemoriaPrincipal()

    def __init__(self):
        pass


    def executar(self):
        for pc in range(len(self.mp.instrucoes)):
            self.cpu.IR = self.mp.instrucoes[pc]
            self.cpu.M  = float(self.mp.dados[pc])
            self.cpu.cicloDeInstrucao()