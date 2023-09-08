attribute vec4 a_position;
uniform mat4 u_matrix;
attribute vec4 a_normal;
varying vec3 v_normal;

void main()
{
    vec4 temp = u_matrix * a_position;
    temp.z = -1.0 * temp.z;
    float dist = 4.0;
    gl_Position = vec4((dist + 1.0) * temp.x, (dist + 1.0) * temp.y, dist * (dist + temp.z) + 1.0 - dist * dist, temp.w * 2.0 * (dist + temp.z));

    v_normal = normalize(vec3(a_normal));
}