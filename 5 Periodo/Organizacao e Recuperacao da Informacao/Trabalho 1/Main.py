# -*- coding: utf-8 -*-
from helpers.Index import *

for i in range(6):
    index = Index(str(i+1)+".txt")
    index.indexar()
    print("TITULO: " + index.titulo)
    print("AUTOR: " + index.autor)

'''
Buscador Web com Flask
    -Instalação: pip3 install flask
    -Documentação- http://flask.pocoo.org/docs/0.12/

from flask import Flask, render_template
app = Flask(__name__)

@app.route("/")
@app.route("/pesquisa/<docs>")
def hello(docs=None):
    return render_template('index.html', docs=doc)

if __name__ == "__main__":
    app.run()
'''
