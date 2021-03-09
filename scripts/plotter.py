#!/usr/bin/env python

import numpy as np
import matplotlib.pyplot as plt

comp_data_bub = np.genfromtxt("../out/bub_sort_comp.txt", delimiter=",", names=["x", "y"])
comp_data_sel = np.genfromtxt("../out/sel_sort_comp.txt", delimiter=",", names=["x", "y"])
comp_data_mrg = np.genfromtxt("../out/mrg_sort_comp.txt", delimiter=",", names=["x", "y"])
comp_data_qck = np.genfromtxt("../out/qck_sort_comp.txt", delimiter=",", names=["x", "y"])

time_data_bub = np.genfromtxt("../out/bub_sort_time.txt", delimiter=",", names=["x", "y"])
time_data_sel = np.genfromtxt("../out/sel_sort_time.txt", delimiter=",", names=["x", "y"])
time_data_mrg = np.genfromtxt("../out/mrg_sort_time.txt", delimiter=",", names=["x", "y"])
time_data_qck = np.genfromtxt("../out/qck_sort_time.txt", delimiter=",", names=["x", "y"])

plt.plot(comp_data_bub["x"], comp_data_bub["y"])
plt.title("Comparison Analysis of Bubble Sort")
plt.xlabel("Size of Input Array")
plt.ylabel("Number of Comparisons.")
plt.savefig("../plots/bub_comp.png")
plt.close()

plt.plot(comp_data_sel["x"], comp_data_sel["y"])
plt.title("Comparison Analysis of Selection Sort")
plt.xlabel("Size of Input Array")
plt.ylabel("Number of Comparisons.")
plt.savefig("../plots/sel_comp.png")
plt.close()

plt.plot(comp_data_mrg["x"], comp_data_mrg["y"])
plt.title("Comparison Analysis of Merge Sort")
plt.xlabel("Size of Input Array")
plt.ylabel("Number of Comparisons.")
plt.savefig("../plots/mrg_comp.png")
plt.close()

plt.plot(comp_data_qck["x"], comp_data_qck["y"])
plt.title("Comparison Analysis of Quick Sort")
plt.xlabel("Size of Input Array")
plt.ylabel("Number of Comparisons.")
plt.savefig("../plots/qck_comp.png")
plt.close()

plt.plot(time_data_bub["x"], time_data_bub["y"])
plt.title("Time Analysis of Bubble Sort")
plt.xlabel("Size of Input Array")
plt.ylabel("Total Execution Time")
plt.savefig("../plots/bub_time.png")
plt.close()

plt.plot(time_data_sel["x"], time_data_sel["y"])
plt.title("Time Analysis of Selection Sort")
plt.xlabel("Size of Input Array")
plt.ylabel("Total Execution Time")
plt.savefig("../plots/sel_time.png")
plt.close()

plt.plot(time_data_mrg["x"], time_data_mrg["y"])
plt.title("Time Analysis of Merge Sort")
plt.xlabel("Size of Input Array")
plt.ylabel("Total Execution Time")
plt.savefig("../plots/mrg_time.png")
plt.close()

plt.plot(time_data_qck["x"], time_data_qck["y"])
plt.title("Time Analysis of Quick Sort")
plt.xlabel("Size of Input Array")
plt.ylabel("Total Execution Time")
plt.savefig("../plots/qck_time.png")
plt.close()