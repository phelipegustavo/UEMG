# -*- coding: utf-8 -*-
from helpers.Index import *

for i in range(10):
    index = Index(str(i+1)+".txt")
    index.indexar()
    print("TITULO: " + index.titulo)
    print("AUTOR: " + index.autor)
