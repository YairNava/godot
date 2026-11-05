/**************************************************************************/
/*  random_number_generator.h                                             */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#pragma once

#include "core/math/random_pcg.h"
#include "core/object/ref_counted.h"

class RandomNumberGenerator : public RefCounted {
	GDCLASS(RandomNumberGenerator, RefCounted);

protected:
	RandomPCG randbase;

	static void _bind_methods();

public:
	_FORCE_INLINE_ void set_seed(uint64_t p_seed) { randbase.seed(p_seed); }
	_FORCE_INLINE_ uint64_t get_seed() { return randbase.get_seed(); }

	_FORCE_INLINE_ void set_state(uint64_t p_state) { randbase.set_state(p_state); }
	_FORCE_INLINE_ uint64_t get_state() const { return randbase.get_state(); }

	_FORCE_INLINE_ void randomize() { randbase.randomize(); }

	_FORCE_INLINE_ uint32_t randi() { return randbase.rand(); }
	_FORCE_INLINE_ real_t randf() { return randbase.randf(); }
	// Wayforge: the single-precision draws whatever real_t is. With precision=double these took
	// randd(), which uses three of the generator's outputs where randf() uses two, so every seeded
	// stream (a world made from its seed) came out different from a single-precision build's.
	_FORCE_INLINE_ real_t randf_range(real_t p_from, real_t p_to) { return randbase.random((float)p_from, (float)p_to); }
	_FORCE_INLINE_ real_t randfn(real_t p_mean = 0.0, real_t p_deviation = 1.0) { return randbase.randfn((float)p_mean, (float)p_deviation); }
	_FORCE_INLINE_ int randi_range(int p_from, int p_to) { return randbase.random(p_from, p_to); }

	_FORCE_INLINE_ int64_t rand_weighted(const Vector<float> &p_weights) { return randbase.rand_weighted(p_weights); }

	RandomNumberGenerator() { randbase.randomize(); }
};
