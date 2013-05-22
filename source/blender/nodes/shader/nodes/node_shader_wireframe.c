/*
 * ***** BEGIN GPL LICENSE BLOCK *****
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version. 
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * The Original Code is Copyright (C) 2005 Blender Foundation.
 * All rights reserved.
 *
 * The Original Code is: all of this file.
 *
 * Contributor(s): none yet.
 *
 * ***** END GPL LICENSE BLOCK *****
 */

#include "../node_shader_util.h"

/* **************** Wireframe ******************** */
static bNodeSocketTemplate sh_node_wireframe_in[] = {
	{	SOCK_FLOAT, 1, N_("Size"),	0.01f, 0.0f, 0.0f, 0.0f, 0.0f, 100.0f},
	{	-1, 0, ""	}
};

static bNodeSocketTemplate sh_node_wireframe_out[] = {
	{	SOCK_FLOAT, 0, N_("Fac"),	0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f},
	{	-1, 0, ""	}
};

/* node type definition */
void register_node_type_sh_wireframe(void)
{
	static bNodeType ntype;

	sh_node_type_base(&ntype, SH_NODE_WIREFRAME, "Wireframe", NODE_CLASS_INPUT, NODE_OPTIONS);
	node_type_compatibility(&ntype, NODE_NEW_SHADING);
	node_type_socket_templates(&ntype, sh_node_wireframe_in, sh_node_wireframe_out);
	node_type_init(&ntype, NULL);
	node_type_storage(&ntype, "", NULL, NULL);

	nodeRegisterType(&ntype);
}