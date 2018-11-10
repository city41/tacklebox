const minXes = {
    CORNER: 0,
    ADVANCED: 6 * 16,
    BEGINNER: 23 * 16,
    OCEAN: 37 * 16,
    OCEAN_ISLAND: 40 * 16
};

const maxXes = {
    CORNER: 5 * 16,
    ADVANCED: 20 * 16,
    BEGINNER: 27 * 16,
    OCEAN: 39 * 16,
    OCEAN_ISLAND: 46 * 16
};

module.exports = {
    getMinX(habitats) {
        const mins = Object.keys(minXes).reduce((building, k) => {
            if (habitats.indexOf(k) > -1) {
                return building.concat(minXes[k]);
            } else {
                return building;
            }
        }, []);

        return Math.min(...mins);
    },

    getMaxX(habitats) {
        const maxes = Object.keys(maxXes).reduce((building, k) => {
            if (habitats.indexOf(k) > -1) {
                return building.concat(maxXes[k]);
            } else {
                return building;
            }
        }, []);

        return Math.max(...maxes);
    }
};
