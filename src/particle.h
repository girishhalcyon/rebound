/**
 * @file 	particle.h
 * @brief 	reb_particle structure and main particle routines.
 * @author 	Hanno Rein <hanno@hanno-rein.de>
 * 
 * @section 	LICENSE
 * Copyright (c) 2011 Hanno Rein, Shangfei Liu
 *
 * This file is part of rebound.
 *
 * rebound is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * rebound is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with rebound.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef _PARTICLE_H
#define _PARTICLE_H
struct reb_context;
struct reb_particle;
struct reb_treecell;


/** 
 * Adds a particle to the simulation. 
 * @details If a tree is used, it also adds the particle to the tree.
 *          If MPI is used, a particle that does not belong to the current node is 
 *          put into the corresponding send queue particles_send.
 * @param pt reb_particle to be added.
 */
void reb_add(struct reb_context* const r, struct reb_particle pt);

/** 
 * Same as reb_add() but inserts particles at given position. 
 * @param pt reb_particle to be added.
 * @param pos New position.
 */
void reb_add_fixed(struct reb_context* const r, struct reb_particle pt,int pos);

/**
 * Add a particle to the particle structure on the current node.
 * Do not distribute particles.
 * @param pt reb_particle to be added.
 */
void reb_add_local(struct reb_context* const r, struct reb_particle pt);

/**
 * Returns the index of the rootbox for the current particles based on its position.
 * @return Index of the rootbox.
 * @param pt reb_particle to be checked.
 */
int reb_get_rootbox_for_particle(const struct reb_context* const r, struct reb_particle pt);

/**
 * Remove all particles
 */
void reb_remove_all(struct reb_context* const r);

/**
 * Remove particle by position in particles array
 * if keepSorted is set, then particles with indices higher than index
 * are all shifted down one position, ensuring the ordering remains.
 * Returns 1 if particle was successfully removed, 0 if index passed was 
 * out of range.
 */
int reb_remove(struct reb_context* const rindex, int ID, int keepSorted);

#ifdef PARTICLEIDS
/**
 * Remove particle by ID.
 * if keepSorted is set, the particles with indices in the particles array
 * higher than the one with the passed ID are all shifted down one position,
 * ensuring the ordering remains. Returns 1 if particle successfully removed,
 * 0 if ID was not found in the particles array.
 */
int reb_remove_with_id(struct reb_context* const r, int ID, int keepSorted);
#endif
#endif // _PARTICLE_H
