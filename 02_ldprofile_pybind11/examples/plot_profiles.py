import numpy as np
import os
import pickle
import ldprofile_pybind11 as ldp
from matplotlib import pyplot as plt

if __name__ == "__main__":
    prof_c = ldp.CoastingLDProfile(1.0)
    prof_gauss = ldp.QGaussianLDProfile(8.0)
    prof_qgauss = ldp.QGaussianLDProfile(3.0 / 5.0, 0.1)

    my_dir = os.path.dirname(__file__)
    with open(my_dir + "/qgauss_dbl_harmonic_data.pkl", "rb") as fp:
        zeta, lambda_dbl_harmonic = pickle.load(fp)

    prof_lin = ldp.LinInterpolLDProfile(zeta[0], zeta[1] - zeta[0], lambda_dbl_harmonic)

    fig, (ax1, ax2, ax3) = plt.subplots(1, 3, figsize=(8,6))
    z = np.linspace(np.min(zeta), np.max(zeta), num=10000, dtype=np.float64)
    ax1.plot(z, prof_c.evaluate(z), label="coasting", color="#984ea3")
    ax1.set_title(
        "Example usage of coasting, QGaussian, and Linear Interpolated LD-Profile"
    )
    ax1.set_xlabel(r"z")
    ax1.set_ylabel(r"line density: $\lambda(z) = \int\; d\delta \; \psi(z, \delta)$")
    ax1.set_ylim(0.0, 1.5)
    ax1.legend()

    ax2.plot(
        z,
        50.0 * prof_gauss.evaluate(z),
        label=r"gaussian, $\sigma=8.0$",
        color="#377eb8",
    )
    ax2.plot(
        z, 50.0 * prof_qgauss.evaluate(z), label=r"q=3/5, $\beta=0.01$", color="#4daf4a"
    )
    ax2.set_ylim(0.0, 6.0)
    ax2.set_xlabel(r"z")
    ax2.legend()

    ax3.plot(z, prof_lin.evaluate(z), label="lin. interpolated", color="#a65628")
    ax3.set_ylim(0.0, 200.0)
    ax3.set_xlabel(r"z")
    ax3.legend()

    plt.show()
