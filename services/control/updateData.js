const sql = /** @type {any} */ (require("sql-template-strings"));
const { query } = require("../../utils/mysql");

const insertStatement = (body) => sql`UPDATE data SET status = ${body.status} WHERE ID = ${body.id}`;

/**
 * 更新排程
 * @param {import('express').Request} req
 * @param {import('express').Response} res
 */
async function updateData(req, res) {
    try {
        const [rows, fields] = await query(insertStatement(req.body), req);
        res.status(200).json({ message: "更新成功" });
    } catch (err) {
        req.flash("error", err);
        res.status(409).json({ errors: [err] });
        console.log(err);
    }
}

module.exports = updateData;
