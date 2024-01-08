import py5

diam = 10
pos_x = 10
i = 5
i_deux = 5

def setup():
        py5.size(400, 400)
def draw():
        global diam,pos_x,i,i_deux
        py5.background(220,0,0)
        py5.fill(120,120,100)
        py5.no_stroke()
        py5.ellipse(pos_x,py5.height/2,diam,diam)
        pos_x = pos_x + i
        if pos_x == py5.width -diam / 2:
                i = (-1) * i
        if pos_x == diam / 2:
                i = i_deux

py5.run_sketch()  # Remplacez run_sketch() par run()


