#!/usr/bin/env python3

# command for running visualizer
# ./lem_in < maps1/2_1.map | visualizer/main.py

import networkx as nx
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import matplotlib.patches as mpatches
from string import ascii_lowercase
import sys

g_ants_finished = 0

def contains_error(instructions):
    for line in instructions:
        if "Error" in line:
            return True
    return False

def parse_edge(line):
    tmp = line.split('-')
    return (tmp[0], tmp[1])

def parse_node(line, nodes):
    tmp = line.split(' ')
    nodes[tmp[0]] = (tmp[1], tmp[2])
    node_name = tmp[0]
    return nodes, node_name

def parse_solver(line):
    line = line.split(' ')
    current = []
    for each in line:
        tmp = each.split('-')
        current.append((tmp[0][1:], tmp[1]))
    return current

def parse_nodelist(instructions, idx, node_name, nodelist):
    if idx and instructions[idx - 1] == '##start':
        nodelist['start'] = [node_name]
    elif idx and instructions[idx - 1] == '##end':
        nodelist['end'] = [node_name]
    else:
        if 'rest' in nodelist.keys():
            nodelist['rest'] = nodelist['rest'] + [node_name]
        else:
            nodelist['rest'] = [node_name]
    return nodelist

def nodelist_start(nodelist):
    return nodelist['start'][0]

def nodelist_end(nodelist):
    return nodelist['end'][0]

def nodelist_rest(nodelist):
    return nodelist['rest']

def generate_colorlist(nodes, nodelist):
    colorlist = []
    for node in nodes:
        if node == ''.join(nodelist['start']):
            colorlist.append('w')
        elif node == ''.join(nodelist['end']):
            colorlist.append('w')
        else:
            colorlist.append('w')
    return colorlist

def instruct_ant(instruction):
    return instruction[0]

def instruct_room(instruction):
    return instruction[1]

def parser(instructions):
    solver, edges, nodes, nodelist = [], [], {}, {}
    for idx in range(len(instructions)):
        if "L" in instructions[idx]:
            solver.append(parse_solver(instructions[idx]))
        elif "-" in instructions[idx]:
            edges.append(parse_edge(instructions[idx]))
        elif len(instructions[idx].split(' ')) == 3:
            nodes, node_name = parse_node(instructions[idx], nodes)
            nodelist = parse_nodelist(instructions, idx, node_name, nodelist)
    return solver, edges, nodes, nodelist

def generate_edgelist(ant_name, room_name, ants):
    cr_idx = 0
    for idx, value in enumerate(ants[ant_name]):
        if value == room_name:
            cr_idx = idx
            break
    head = ants[ant_name][cr_idx - 1]
    tail = ants[ant_name][cr_idx]
    tmp = (head, tail)
    return tmp

def offset_se(pos, nodelist):
    for key, value in pos.items():
        if key == nodelist_start(nodelist) or key == nodelist_end(nodelist):
            pos[key] = [value[0], value[1] - 0.15]
    return pos

def position_se(pos, nodelist):
    start_pos = pos[nodelist_start(nodelist)] 
    end_pos = pos[nodelist_end(nodelist)]
    start_xy = [start_pos[0], start_pos[1] - 0.15]
    end_xy = [end_pos[0], end_pos[1] - 0.15]
    pos['_start'] = start_xy
    pos['_end'] = end_xy
    return pos


def label_se(G, pos, nodelist):
    labellist = {'_start': 'start', '_end': 'end'}
    pos = position_se(pos, nodelist)
    nx.draw_networkx_labels(G, pos=pos, labels=labellist, font_size=10, font_weight='bold')

def run_solver(frame, G, pos, solver, ants, colorlist, nodelist, fig, frame_count):
    global g_ants_finished

    if frame == frame_count - 1:
        draw_networkx_base(G, fig, pos, colorlist, nodelist, None, False)
    elif frame:
        ant_labels = {}
        edgelist = []
        for instruction in solver[frame - 1]:
            ant_name = instruct_ant(instruction)
            room_name = instruct_room(instruction)
            if room_name == 'end':
                g_ants_finished = g_ants_finished + 1
            ant_labels[room_name] = ant_name            
            edgelist.append(generate_edgelist(ant_name, room_name, ants))
        draw_networkx_base(G, fig, pos, colorlist, nodelist, ant_labels, True)
        nx.draw_networkx_edges(G, pos=pos, edgelist=edgelist, edge_color='g', width=2.0)

def generate_ants(solver, nodelist):
    ants = {}
    for line in solver:
        for instruction in line:
            ant_name = instruct_ant(instruction)
            room_name = instruct_room(instruction)
            if ant_name in ants.keys():
                ants[ant_name] += [room_name]
            else:
                ants[ant_name] = [nodelist_start(nodelist), room_name]
    return ants

def label_ants_finished(G, pos):
    labels = {'ants_finished': 'ants finished: ' + str(g_ants_finished)}
    pos['ants_finished'] = [-0.75, 0.85]
    nx.draw_networkx_labels(G, pos=pos, labels=labels, font_size=10, font_weight='bold')

def draw_networkx_base(G, fig, pos, colorlist, nodelist, labels, with_labels):
    print(labels)
    plt.clf()
    plt.title('Graph Representation of Lem-In Optimization Algorithm', size=12)
    nx.draw(G, pos=pos, node_color=colorlist, labels=labels, with_labels=with_labels, width=2.0, node_size=1000)
    label_se(G, pos, nodelist)
    label_ants_finished(G, pos)
    fig.set_facecolor('grey')
    plt.axis('off')

def visualize(solver, edges, nodes, nodelist):
    G = nx.Graph()
    fig, ax = plt.subplots()
    colorlist = generate_colorlist(nodes, nodelist)
    ants = generate_ants(solver, nodelist)
    frame_count = len(solver) + 2
    G.add_nodes_from(nodes)
    G.add_edges_from(edges)
    pos = nx.shell_layout(G)
    draw_networkx_base(G, fig, pos, colorlist, nodelist, None, False)
    fargs= (G, pos, solver, ants, colorlist, nodelist, fig, frame_count)
    anim = animation.FuncAnimation(fig, run_solver, frames=frame_count, fargs=fargs, interval=3000, repeat=False)
    plt.show()

def main():
    instructions = []

    for line in sys.stdin:
        if line:
            instructions.append(line.rstrip())

    if contains_error(instructions):
        print('Error has occurred')
        return
    
    solver, edges, nodes, nodelist = parser(instructions)
    visualize(solver, edges, nodes, nodelist)
  
if __name__== "__main__":
  main()